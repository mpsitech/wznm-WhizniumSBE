/**
	* \file PnlWznmRelRec.h
	* job handler for job PnlWznmRelRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMRELREC_H
#define PNLWZNMRELREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmRelRef1NDialog.h"
#include "PnlWznmRelRef1NPanel.h"
#include "PnlWznmRelRef1NControl.h"
#include "PnlWznmRelSup1NRelation.h"
#include "PnlWznmRel1NTablecol.h"
#include "PnlWznmRelATitle.h"
#include "PnlWznmRelDetail.h"

#define VecVWznmRelRecDo PnlWznmRelRec::VecVDo

#define ContInfWznmRelRec PnlWznmRelRec::ContInf
#define StatAppWznmRelRec PnlWznmRelRec::StatApp
#define StatShrWznmRelRec PnlWznmRelRec::StatShr
#define TagWznmRelRec PnlWznmRelRec::Tag

#define DpchAppWznmRelRecDo PnlWznmRelRec::DpchAppDo
#define DpchEngWznmRelRecData PnlWznmRelRec::DpchEngData

/**
	* PnlWznmRelRec
	*/
class PnlWznmRelRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmRelRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmRelRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmRelRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NTablecol = false, const bool initdoneSup1NRelation = false, const bool initdoneRef1NControl = false, const bool initdoneRef1NPanel = false, const bool initdoneRef1NDialog = false);
	};

	/**
		* StatShr (full: StatShrWznmRelRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFATITLE = 3;
		static const Sbecore::uint JREF1NTABLECOL = 4;
		static const Sbecore::uint JREFSUP1NRELATION = 5;
		static const Sbecore::uint JREFREF1NCONTROL = 6;
		static const Sbecore::uint JREFREF1NPANEL = 7;
		static const Sbecore::uint JREFREF1NDIALOG = 8;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefATitle = 0, const Sbecore::ubigint jref1NTablecol = 0, const Sbecore::ubigint jrefSup1NRelation = 0, const Sbecore::ubigint jrefRef1NControl = 0, const Sbecore::ubigint jrefRef1NPanel = 0, const Sbecore::ubigint jrefRef1NDialog = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefATitle;
		Sbecore::ubigint jref1NTablecol;
		Sbecore::ubigint jrefSup1NRelation;
		Sbecore::ubigint jrefRef1NControl;
		Sbecore::ubigint jrefRef1NPanel;
		Sbecore::ubigint jrefRef1NDialog;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmRelRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmRelRecDo)
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
		* DpchEngData (full: DpchEngWznmRelRecData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmRelRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmRelRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmRelRef1NDialog* pnlref1ndialog;
	PnlWznmRelRef1NPanel* pnlref1npanel;
	PnlWznmRelRef1NControl* pnlref1ncontrol;
	PnlWznmRelSup1NRelation* pnlsup1nrelation;
	PnlWznmRel1NTablecol* pnl1ntablecol;
	PnlWznmRelATitle* pnlatitle;
	PnlWznmRelDetail* pnldetail;

	WznmMRelation recRel;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);
	void regularize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmRelUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmRel_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_tosEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_supEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_frsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmRel_cluEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif



