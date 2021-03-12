/**
	* \file PnlWznmLibRec.h
	* job handler for job PnlWznmLibRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMLIBREC_H
#define PNLWZNMLIBREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmLibMNComponent.h"
#include "PnlWznmLibMNOppack.h"
#include "PnlWznmLibRef1NFile.h"
#include "PnlWznmLibAMakefile.h"
#include "PnlWznmLibAPkglist.h"
#include "PnlWznmLibDetail.h"

#define VecVWznmLibRecDo PnlWznmLibRec::VecVDo

#define ContInfWznmLibRec PnlWznmLibRec::ContInf
#define StatAppWznmLibRec PnlWznmLibRec::StatApp
#define StatShrWznmLibRec PnlWznmLibRec::StatShr
#define TagWznmLibRec PnlWznmLibRec::Tag

#define DpchAppWznmLibRecDo PnlWznmLibRec::DpchAppDo
#define DpchEngWznmLibRecData PnlWznmLibRec::DpchEngData

/**
	* PnlWznmLibRec
	*/
class PnlWznmLibRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmLibRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmLibRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmLibRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneAPkglist = false, const bool initdoneAMakefile = false, const bool initdoneRef1NFile = false, const bool initdoneMNOppack = false, const bool initdoneMNComponent = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAPkglist = false, const bool initdoneAMakefile = false, const bool initdoneRef1NFile = false, const bool initdoneMNOppack = false, const bool initdoneMNComponent = false);
	};

	/**
		* StatShr (full: StatShrWznmLibRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAPKGLIST = 3;
		static const Sbecore::uint JREFAMAKEFILE = 4;
		static const Sbecore::uint JREFREF1NFILE = 5;
		static const Sbecore::uint JREFMNOPPACK = 6;
		static const Sbecore::uint JREFMNCOMPONENT = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAPkglist = 0, const Sbecore::ubigint jrefAMakefile = 0, const Sbecore::ubigint jrefRef1NFile = 0, const Sbecore::ubigint jrefMNOppack = 0, const Sbecore::ubigint jrefMNComponent = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAPkglist;
		Sbecore::ubigint jrefAMakefile;
		Sbecore::ubigint jrefRef1NFile;
		Sbecore::ubigint jrefMNOppack;
		Sbecore::ubigint jrefMNComponent;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmLibRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmLibRecDo)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmLibRecData)
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

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmLibRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmLibRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmLibMNComponent* pnlmncomponent;
	PnlWznmLibMNOppack* pnlmnoppack;
	PnlWznmLibRef1NFile* pnlref1nfile;
	PnlWznmLibAMakefile* pnlamakefile;
	PnlWznmLibAPkglist* pnlapkglist;
	PnlWznmLibDetail* pnldetail;

	WznmMLibrary recLib;

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
	bool handleCallWznmLibUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
