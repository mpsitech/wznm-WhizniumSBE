/**
	* \file PnlWznmCarDetail.h
	* job handler for job PnlWznmCarDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCARDETAIL_H
#define PNLWZNMCARDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmCarDetailDo PnlWznmCarDetail::VecVDo

#define ContIacWznmCarDetail PnlWznmCarDetail::ContIac
#define ContInfWznmCarDetail PnlWznmCarDetail::ContInf
#define StatAppWznmCarDetail PnlWznmCarDetail::StatApp
#define StatShrWznmCarDetail PnlWznmCarDetail::StatShr
#define TagWznmCarDetail PnlWznmCarDetail::Tag

#define DpchAppWznmCarDetailData PnlWznmCarDetail::DpchAppData
#define DpchAppWznmCarDetailDo PnlWznmCarDetail::DpchAppDo
#define DpchEngWznmCarDetailData PnlWznmCarDetail::DpchEngData

/**
	* PnlWznmCarDetail
	*/
class PnlWznmCarDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmCarDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTMDLVIEWCLICK = 3;
		static const Sbecore::uint BUTREUVIEWCLICK = 4;
		static const Sbecore::uint BUTJOBVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmCarDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFAVL = 3;
		static const Sbecore::uint TXFACT = 4;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupRet = 1, const std::string& TxfAvl = "", const std::string& TxfAct = "");

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupRet;
		std::string TxfAvl;
		std::string TxfAct;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmCarDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTREU = 4;
		static const Sbecore::uint TXTJOB = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtMdl = "", const std::string& TxtReu = "", const std::string& TxtJob = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtMdl;
		std::string TxtReu;
		std::string TxtJob;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmCarDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWznmCarDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJTIACTIVE = 4;
		static const Sbecore::uint BUTJTIEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTMDLACTIVE = 7;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 8;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint TXTJOBACTIVE = 13;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 14;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 15;
		static const Sbecore::uint TXFAVLACTIVE = 16;
		static const Sbecore::uint TXFACTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfAvlActive = true, const bool TxfActActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfAvlActive;
		bool TxfActActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmCarDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmCarDetailData)
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
		* DpchAppDo (full: DpchAppWznmCarDetailDo)
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
		* DpchEngData (full: DpchEngWznmCarDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJTI = 4;
		static const Sbecore::uint FEEDFPUPRET = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupJti = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJti;
		Sbecore::Xmlio::Feed feedFPupRet;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWznm* dbswznm);
	bool evalButSaveActive(DbsWznm* dbswznm);
	bool evalTxtSrfActive(DbsWznm* dbswznm);
	bool evalPupJtiActive(DbsWznm* dbswznm);
	bool evalButJtiEditAvail(DbsWznm* dbswznm);
	bool evalTxtTitActive(DbsWznm* dbswznm);
	bool evalTxtMdlActive(DbsWznm* dbswznm);
	bool evalButMdlViewAvail(DbsWznm* dbswznm);
	bool evalButMdlViewActive(DbsWznm* dbswznm);
	bool evalTxtReuActive(DbsWznm* dbswznm);
	bool evalButReuViewAvail(DbsWznm* dbswznm);
	bool evalButReuViewActive(DbsWznm* dbswznm);
	bool evalTxtJobActive(DbsWznm* dbswznm);
	bool evalButJobViewAvail(DbsWznm* dbswznm);
	bool evalButJobViewActive(DbsWznm* dbswznm);
	bool evalTxfAvlActive(DbsWznm* dbswznm);
	bool evalTxfActActive(DbsWznm* dbswznm);

public:
	PnlWznmCarDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmCarDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupJti;
	Sbecore::Xmlio::Feed feedFPupRet;

	WznmMCard recCar;

	WznmJMCardTitle recCarJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecCar(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecCarJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButMdlViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmCarJtitMod_carEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmCarUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmCar_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmCar_mdlEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmCar_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmCar_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
