/**
	* \file PnlWznmTagDetail.h
	* job handler for job PnlWznmTagDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef PNLWZNMTAGDETAIL_H
#define PNLWZNMTAGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWznmTagDetailDo PnlWznmTagDetail::VecVDo

#define ContIacWznmTagDetail PnlWznmTagDetail::ContIac
#define ContInfWznmTagDetail PnlWznmTagDetail::ContInf
#define StatAppWznmTagDetail PnlWznmTagDetail::StatApp
#define StatShrWznmTagDetail PnlWznmTagDetail::StatShr
#define TagWznmTagDetail PnlWznmTagDetail::Tag

#define DpchAppWznmTagDetailData PnlWznmTagDetail::DpchAppData
#define DpchAppWznmTagDetailDo PnlWznmTagDetail::DpchAppDo
#define DpchEngWznmTagDetailData PnlWznmTagDetail::DpchEngData

/**
	* PnlWznmTagDetail
	*/
class PnlWznmTagDetail : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTagDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJTIEDITCLICK = 2;
		static const Sbecore::uint BUTCPBVIEWCLICK = 3;
		static const Sbecore::uint BUTGRPEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWznmTagDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJTI = 1;
		static const Sbecore::uint NUMFPUPGRP = 2;
		static const Sbecore::uint TXFGRP = 3;

	public:
		ContIac(const Sbecore::uint numFPupJti = 1, const Sbecore::uint numFPupGrp = 1, const std::string& TxfGrp = "");

	public:
		Sbecore::uint numFPupJti;
		Sbecore::uint numFPupGrp;
		std::string TxfGrp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWznmTagDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTCPB = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtCpb = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtCpb;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmTagDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::MIND, const bool PupGrpAlt = false);
	};

	/**
		* StatShr (full: StatShrWznmTagDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFGRPVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPJTIACTIVE = 5;
		static const Sbecore::uint BUTJTIEDITAVAIL = 6;
		static const Sbecore::uint TXTTITACTIVE = 7;
		static const Sbecore::uint TXTCPBACTIVE = 8;
		static const Sbecore::uint BUTCPBVIEWAVAIL = 9;
		static const Sbecore::uint BUTCPBVIEWACTIVE = 10;
		static const Sbecore::uint PUPGRPACTIVE = 11;
		static const Sbecore::uint BUTGRPEDITAVAIL = 12;

	public:
		StatShr(const bool TxfGrpValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJtiActive = true, const bool ButJtiEditAvail = true, const bool TxtTitActive = true, const bool TxtCpbActive = true, const bool ButCpbViewAvail = true, const bool ButCpbViewActive = true, const bool PupGrpActive = true, const bool ButGrpEditAvail = true);

	public:
		bool TxfGrpValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJtiActive;
		bool ButJtiEditAvail;
		bool TxtTitActive;
		bool TxtCpbActive;
		bool ButCpbViewAvail;
		bool ButCpbViewActive;
		bool PupGrpActive;
		bool ButGrpEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmTagDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWznmTagDetailData)
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
		* DpchAppDo (full: DpchAppWznmTagDetailDo)
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
		* DpchEngData (full: DpchEngWznmTagDetailData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPGRP = 4;
		static const Sbecore::uint FEEDFPUPJTI = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupGrp = NULL, Sbecore::Xmlio::Feed* feedFPupJti = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupGrp;
		Sbecore::Xmlio::Feed feedFPupJti;
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
	bool evalTxtCpbActive(DbsWznm* dbswznm);
	bool evalButCpbViewAvail(DbsWznm* dbswznm);
	bool evalButCpbViewActive(DbsWznm* dbswznm);
	bool evalPupGrpActive(DbsWznm* dbswznm);
	bool evalButGrpEditAvail(DbsWznm* dbswznm);

public:
	PnlWznmTagDetail(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTagDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupGrp;
	Sbecore::Xmlio::Feed feedFPupJti;

	WznmMTag recTag;

	WznmJMTagTitle recTagJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJti(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshPupGrp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshTxfGrp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshGrp(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refreshRecTag(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
	void refreshRecTagJtit(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButJtiEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButCpbViewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButGrpEditClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmTagJtitMod_tagEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmKlsAkeyMod_klsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWznmTagUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmTag_cpbEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

