/**
	* \file ApiWznm.cpp
	* Wznm API library global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "ApiWznm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class StgWznmapi
 ******************************************************************************/

StgWznmapi::StgWznmapi(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			Block()
			, engip(engip)
			, engport(engport)
			, username(username)
			, password(password)
		{
	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD};
};

bool StgWznmapi::all(
			const set<uint>& items
		) {
	if (!find(items, ENGIP)) return false;
	if (!find(items, ENGPORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgWznmapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWznmapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWznmapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgWznmapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWznmapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemWznmapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWznmapi::compare(
			const StgWznmapi* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiWznm
 ******************************************************************************/

uint ApiWznm::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngWznm** dpcheng
		) {
	uint ixWznmVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(buf, buflen, &doc, &docctx);

		ixWznmVDpch = VecWznmVDpch::getIx(extractRoot(doc));

		if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMAPPIMPSTRDATA) {
			*dpcheng = new DlgWznmAppImpstr::DpchEngData();
			((DlgWznmAppImpstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMAPPNEWDATA) {
			*dpcheng = new DlgWznmAppNew::DpchEngData();
			((DlgWznmAppNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMAPPWRITEDATA) {
			*dpcheng = new DlgWznmAppWrite::DpchEngData();
			((DlgWznmAppWrite::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMFILDOWNLOADDATA) {
			*dpcheng = new DlgWznmFilDownload::DpchEngData();
			((DlgWznmFilDownload::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMFILNEWDATA) {
			*dpcheng = new DlgWznmFilNew::DpchEngData();
			((DlgWznmFilNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMMCHWRINISCRDATA) {
			*dpcheng = new DlgWznmMchWriniscr::DpchEngData();
			((DlgWznmMchWriniscr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMNAVLOAINIDATA) {
			*dpcheng = new DlgWznmNavLoaini::DpchEngData();
			((DlgWznmNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMNAVMNGLICDATA) {
			*dpcheng = new DlgWznmNavMnglic::DpchEngData();
			((DlgWznmNavMnglic::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMPRJIMPEXDATA) {
			*dpcheng = new DlgWznmPrjImpex::DpchEngData();
			((DlgWznmPrjImpex::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMPRJNEWDATA) {
			*dpcheng = new DlgWznmPrjNew::DpchEngData();
			((DlgWznmPrjNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMRLSFINREPTRDATA) {
			*dpcheng = new DlgWznmRlsFinreptr::DpchEngData();
			((DlgWznmRlsFinreptr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMRLSSTAREPTRDATA) {
			*dpcheng = new DlgWznmRlsStareptr::DpchEngData();
			((DlgWznmRlsStareptr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMRLSWRITEDATA) {
			*dpcheng = new DlgWznmRlsWrite::DpchEngData();
			((DlgWznmRlsWrite::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMUSRMNGKEYPAIRDATA) {
			*dpcheng = new DlgWznmUsrMngkeypair::DpchEngData();
			((DlgWznmUsrMngkeypair::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMUTLEXTRIPDATA) {
			*dpcheng = new DlgWznmUtlExtrip::DpchEngData();
			((DlgWznmUtlExtrip::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMUTLMRGIPDATA) {
			*dpcheng = new DlgWznmUtlMrgip::DpchEngData();
			((DlgWznmUtlMrgip::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERBSCUIDATA) {
			*dpcheng = new DlgWznmVerBscui::DpchEngData();
			((DlgWznmVerBscui::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERCUSTJOBDATA) {
			*dpcheng = new DlgWznmVerCustjob::DpchEngData();
			((DlgWznmVerCustjob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERCUSTJTRDATA) {
			*dpcheng = new DlgWznmVerCustjtr::DpchEngData();
			((DlgWznmVerCustjtr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERCUSTUIDATA) {
			*dpcheng = new DlgWznmVerCustui::DpchEngData();
			((DlgWznmVerCustui::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERDBSTRDATA) {
			*dpcheng = new DlgWznmVerDbstr::DpchEngData();
			((DlgWznmVerDbstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERDEPLOYDATA) {
			*dpcheng = new DlgWznmVerDeploy::DpchEngData();
			((DlgWznmVerDeploy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERFINMODDATA) {
			*dpcheng = new DlgWznmVerFinmod::DpchEngData();
			((DlgWznmVerFinmod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERGENJTRDATA) {
			*dpcheng = new DlgWznmVerGenjtr::DpchEngData();
			((DlgWznmVerGenjtr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERGENUIDATA) {
			*dpcheng = new DlgWznmVerGenui::DpchEngData();
			((DlgWznmVerGenui::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERGLOBALDATA) {
			*dpcheng = new DlgWznmVerGlobal::DpchEngData();
			((DlgWznmVerGlobal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERIMPEXPDATA) {
			*dpcheng = new DlgWznmVerImpexp::DpchEngData();
			((DlgWznmVerImpexp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERNEWDATA) {
			*dpcheng = new DlgWznmVerNew::DpchEngData();
			((DlgWznmVerNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVEROPPACKDATA) {
			*dpcheng = new DlgWznmVerOppack::DpchEngData();
			((DlgWznmVerOppack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVERWRINIMDLDATA) {
			*dpcheng = new DlgWznmVerWrinimdl::DpchEngData();
			((DlgWznmVerWrinimdl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVISEXPSTRDATA) {
			*dpcheng = new DlgWznmVisExpstr::DpchEngData();
			((DlgWznmVisExpstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVISIMPSTRDATA) {
			*dpcheng = new DlgWznmVisImpstr::DpchEngData();
			((DlgWznmVisImpstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVISMISSFEATDATA) {
			*dpcheng = new DlgWznmVisMissfeat::DpchEngData();
			((DlgWznmVisMissfeat::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVISNEWDATA) {
			*dpcheng = new DlgWznmVisNew::DpchEngData();
			((DlgWznmVisNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGDLGWZNMVISWRITEDATA) {
			*dpcheng = new DlgWznmVisWrite::DpchEngData();
			((DlgWznmVisWrite::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGROOTWZNMDATA) {
			*dpcheng = new RootWznm::DpchEngData();
			((RootWznm::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGSESSWZNMDATA) {
			*dpcheng = new SessWznm::DpchEngData();
			((SessWznm::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMACK) {
			*dpcheng = new DpchEngWznmAck();
			((DpchEngWznmAck*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMALERT) {
			*dpcheng = new DpchEngWznmAlert();
			((DpchEngWznmAlert*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPP1NEVENTDATA) {
			*dpcheng = new PnlWznmApp1NEvent::DpchEngData();
			((PnlWznmApp1NEvent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPP1NRTJOBDATA) {
			*dpcheng = new PnlWznmApp1NRtjob::DpchEngData();
			((PnlWznmApp1NRtjob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPAPP1NSEQUENCEDATA) {
			*dpcheng = new PnlWznmAppApp1NSequence::DpchEngData();
			((PnlWznmAppApp1NSequence::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPDATA) {
			*dpcheng = new CrdWznmApp::DpchEngData();
			((CrdWznmApp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPDETAILDATA) {
			*dpcheng = new PnlWznmAppDetail::DpchEngData();
			((PnlWznmAppDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPHEADBARDATA) {
			*dpcheng = new PnlWznmAppHeadbar::DpchEngData();
			((PnlWznmAppHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPLISTDATA) {
			*dpcheng = new PnlWznmAppList::DpchEngData();
			((PnlWznmAppList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPRECDATA) {
			*dpcheng = new PnlWznmAppRec::DpchEngData();
			((PnlWznmAppRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMAPPREF1NFILEDATA) {
			*dpcheng = new PnlWznmAppRef1NFile::DpchEngData();
			((PnlWznmAppRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLK1NRTDPCHDATA) {
			*dpcheng = new PnlWznmBlk1NRtdpch::DpchEngData();
			((PnlWznmBlk1NRtdpch::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKAITEMDATA) {
			*dpcheng = new PnlWznmBlkAItem::DpchEngData();
			((PnlWznmBlkAItem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKDATA) {
			*dpcheng = new CrdWznmBlk::DpchEngData();
			((CrdWznmBlk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKDETAILDATA) {
			*dpcheng = new PnlWznmBlkDetail::DpchEngData();
			((PnlWznmBlkDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKHEADBARDATA) {
			*dpcheng = new PnlWznmBlkHeadbar::DpchEngData();
			((PnlWznmBlkHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKLISTDATA) {
			*dpcheng = new PnlWznmBlkList::DpchEngData();
			((PnlWznmBlkList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKRECDATA) {
			*dpcheng = new PnlWznmBlkRec::DpchEngData();
			((PnlWznmBlkRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBLKREF1NRTBLOCKDATA) {
			*dpcheng = new PnlWznmBlkRef1NRtblock::DpchEngData();
			((PnlWznmBlkRef1NRtblock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXDATA) {
			*dpcheng = new CrdWznmBox::DpchEngData();
			((CrdWznmBox::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXDETAILDATA) {
			*dpcheng = new PnlWznmBoxDetail::DpchEngData();
			((PnlWznmBoxDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXDSTMNBOXDATA) {
			*dpcheng = new PnlWznmBoxDstMNBox::DpchEngData();
			((PnlWznmBoxDstMNBox::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXHEADBARDATA) {
			*dpcheng = new PnlWznmBoxHeadbar::DpchEngData();
			((PnlWznmBoxHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXLISTDATA) {
			*dpcheng = new PnlWznmBoxList::DpchEngData();
			((PnlWznmBoxList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXORGMNBOXDATA) {
			*dpcheng = new PnlWznmBoxOrgMNBox::DpchEngData();
			((PnlWznmBoxOrgMNBox::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMBOXRECDATA) {
			*dpcheng = new PnlWznmBoxRec::DpchEngData();
			((PnlWznmBoxRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAL1NSENSITIVITYDATA) {
			*dpcheng = new PnlWznmCal1NSensitivity::DpchEngData();
			((PnlWznmCal1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALDATA) {
			*dpcheng = new CrdWznmCal::DpchEngData();
			((CrdWznmCal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALDETAILDATA) {
			*dpcheng = new PnlWznmCalDetail::DpchEngData();
			((PnlWznmCalDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALHEADBARDATA) {
			*dpcheng = new PnlWznmCalHeadbar::DpchEngData();
			((PnlWznmCalHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALLISTDATA) {
			*dpcheng = new PnlWznmCalList::DpchEngData();
			((PnlWznmCalList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALMNSTUBDATA) {
			*dpcheng = new PnlWznmCalMNStub::DpchEngData();
			((PnlWznmCalMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCALRECDATA) {
			*dpcheng = new PnlWznmCalRec::DpchEngData();
			((PnlWznmCalRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPAPARDATA) {
			*dpcheng = new PnlWznmCapAPar::DpchEngData();
			((PnlWznmCapAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPDATA) {
			*dpcheng = new CrdWznmCap::DpchEngData();
			((CrdWznmCap::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPDETAILDATA) {
			*dpcheng = new PnlWznmCapDetail::DpchEngData();
			((PnlWznmCapDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPHEADBARDATA) {
			*dpcheng = new PnlWznmCapHeadbar::DpchEngData();
			((PnlWznmCapHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPLISTDATA) {
			*dpcheng = new PnlWznmCapList::DpchEngData();
			((PnlWznmCapList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAPRECDATA) {
			*dpcheng = new PnlWznmCapRec::DpchEngData();
			((PnlWznmCapRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCAR1NDIALOGDATA) {
			*dpcheng = new PnlWznmCar1NDialog::DpchEngData();
			((PnlWznmCar1NDialog::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARCAR1NPANELDATA) {
			*dpcheng = new PnlWznmCarCar1NPanel::DpchEngData();
			((PnlWznmCarCar1NPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARDATA) {
			*dpcheng = new CrdWznmCar::DpchEngData();
			((CrdWznmCar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARDETAILDATA) {
			*dpcheng = new PnlWznmCarDetail::DpchEngData();
			((PnlWznmCarDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARHEADBARDATA) {
			*dpcheng = new PnlWznmCarHeadbar::DpchEngData();
			((PnlWznmCarHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARHK1NCONTROLDATA) {
			*dpcheng = new PnlWznmCarHk1NControl::DpchEngData();
			((PnlWznmCarHk1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARLISTDATA) {
			*dpcheng = new PnlWznmCarList::DpchEngData();
			((PnlWznmCarList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCARRECDATA) {
			*dpcheng = new PnlWznmCarRec::DpchEngData();
			((PnlWznmCarRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKDATA) {
			*dpcheng = new CrdWznmChk::DpchEngData();
			((CrdWznmChk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKDETAILDATA) {
			*dpcheng = new PnlWznmChkDetail::DpchEngData();
			((PnlWznmChkDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKHEADBARDATA) {
			*dpcheng = new PnlWznmChkHeadbar::DpchEngData();
			((PnlWznmChkHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKLISTDATA) {
			*dpcheng = new PnlWznmChkList::DpchEngData();
			((PnlWznmChkList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKRECDATA) {
			*dpcheng = new PnlWznmChkRec::DpchEngData();
			((PnlWznmChkRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCHKREF1NCALLDATA) {
			*dpcheng = new PnlWznmChkRef1NCall::DpchEngData();
			((PnlWznmChkRef1NCall::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMP1NRELEASEDATA) {
			*dpcheng = new PnlWznmCmp1NRelease::DpchEngData();
			((PnlWznmCmp1NRelease::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPDATA) {
			*dpcheng = new CrdWznmCmp::DpchEngData();
			((CrdWznmCmp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPDETAILDATA) {
			*dpcheng = new PnlWznmCmpDetail::DpchEngData();
			((PnlWznmCmpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPHEADBARDATA) {
			*dpcheng = new PnlWznmCmpHeadbar::DpchEngData();
			((PnlWznmCmpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPLISTDATA) {
			*dpcheng = new PnlWznmCmpList::DpchEngData();
			((PnlWznmCmpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPMNLIBRARYDATA) {
			*dpcheng = new PnlWznmCmpMNLibrary::DpchEngData();
			((PnlWznmCmpMNLibrary::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPMNOPPACKDATA) {
			*dpcheng = new PnlWznmCmpMNOppack::DpchEngData();
			((PnlWznmCmpMNOppack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCMPRECDATA) {
			*dpcheng = new PnlWznmCmpRec::DpchEngData();
			((PnlWznmCmpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONAPARDATA) {
			*dpcheng = new PnlWznmConAPar::DpchEngData();
			((PnlWznmConAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONDATA) {
			*dpcheng = new CrdWznmCon::DpchEngData();
			((CrdWznmCon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONDETAILDATA) {
			*dpcheng = new PnlWznmConDetail::DpchEngData();
			((PnlWznmConDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONFEDREF1NRTBLOCKDATA) {
			*dpcheng = new PnlWznmConFedRef1NRtblock::DpchEngData();
			((PnlWznmConFedRef1NRtblock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONFIRM) {
			*dpcheng = new DpchEngWznmConfirm();
			((DpchEngWznmConfirm*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONHEADBARDATA) {
			*dpcheng = new PnlWznmConHeadbar::DpchEngData();
			((PnlWznmConHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONLISTDATA) {
			*dpcheng = new PnlWznmConList::DpchEngData();
			((PnlWznmConList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONRECDATA) {
			*dpcheng = new PnlWznmConRec::DpchEngData();
			((PnlWznmConRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCONSUP1NCONTROLDATA) {
			*dpcheng = new PnlWznmConSup1NControl::DpchEngData();
			((PnlWznmConSup1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTP1NTAGDATA) {
			*dpcheng = new PnlWznmCtp1NTag::DpchEngData();
			((PnlWznmCtp1NTag::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPAPARDATA) {
			*dpcheng = new PnlWznmCtpAPar::DpchEngData();
			((PnlWznmCtpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPDATA) {
			*dpcheng = new CrdWznmCtp::DpchEngData();
			((CrdWznmCtp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPDETAILDATA) {
			*dpcheng = new PnlWznmCtpDetail::DpchEngData();
			((PnlWznmCtpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPHEADBARDATA) {
			*dpcheng = new PnlWznmCtpHeadbar::DpchEngData();
			((PnlWznmCtpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPKKEYDATA) {
			*dpcheng = new PnlWznmCtpKKey::DpchEngData();
			((PnlWznmCtpKKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPKPARKEYDATA) {
			*dpcheng = new PnlWznmCtpKParKey::DpchEngData();
			((PnlWznmCtpKParKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPLISTDATA) {
			*dpcheng = new PnlWznmCtpList::DpchEngData();
			((PnlWznmCtpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPRECDATA) {
			*dpcheng = new PnlWznmCtpRec::DpchEngData();
			((PnlWznmCtpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMCTPTPL1NCAPABILITYDATA) {
			*dpcheng = new PnlWznmCtpTpl1NCapability::DpchEngData();
			((PnlWznmCtpTpl1NCapability::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGDATA) {
			*dpcheng = new CrdWznmDlg::DpchEngData();
			((CrdWznmDlg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGDETAILDATA) {
			*dpcheng = new PnlWznmDlgDetail::DpchEngData();
			((PnlWznmDlgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGHEADBARDATA) {
			*dpcheng = new PnlWznmDlgHeadbar::DpchEngData();
			((PnlWznmDlgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGHK1NCONTROLDATA) {
			*dpcheng = new PnlWznmDlgHk1NControl::DpchEngData();
			((PnlWznmDlgHk1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGLISTDATA) {
			*dpcheng = new PnlWznmDlgList::DpchEngData();
			((PnlWznmDlgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGMNQUERYDATA) {
			*dpcheng = new PnlWznmDlgMNQuery::DpchEngData();
			((PnlWznmDlgMNQuery::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGRECDATA) {
			*dpcheng = new PnlWznmDlgRec::DpchEngData();
			((PnlWznmDlgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMDLGREF1NCONTROLDATA) {
			*dpcheng = new PnlWznmDlgRef1NControl::DpchEngData();
			((PnlWznmDlgRef1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMERRDATA) {
			*dpcheng = new CrdWznmErr::DpchEngData();
			((CrdWznmErr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMERRDETAILDATA) {
			*dpcheng = new PnlWznmErrDetail::DpchEngData();
			((PnlWznmErrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMERRHEADBARDATA) {
			*dpcheng = new PnlWznmErrHeadbar::DpchEngData();
			((PnlWznmErrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMERRLISTDATA) {
			*dpcheng = new PnlWznmErrList::DpchEngData();
			((PnlWznmErrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMERRRECDATA) {
			*dpcheng = new PnlWznmErrRec::DpchEngData();
			((PnlWznmErrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMEVTDATA) {
			*dpcheng = new CrdWznmEvt::DpchEngData();
			((CrdWznmEvt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMEVTDETAILDATA) {
			*dpcheng = new PnlWznmEvtDetail::DpchEngData();
			((PnlWznmEvtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMEVTHEADBARDATA) {
			*dpcheng = new PnlWznmEvtHeadbar::DpchEngData();
			((PnlWznmEvtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMEVTLISTDATA) {
			*dpcheng = new PnlWznmEvtList::DpchEngData();
			((PnlWznmEvtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMEVTRECDATA) {
			*dpcheng = new PnlWznmEvtRec::DpchEngData();
			((PnlWznmEvtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMFILDATA) {
			*dpcheng = new CrdWznmFil::DpchEngData();
			((CrdWznmFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMFILDETAILDATA) {
			*dpcheng = new PnlWznmFilDetail::DpchEngData();
			((PnlWznmFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMFILHEADBARDATA) {
			*dpcheng = new PnlWznmFilHeadbar::DpchEngData();
			((PnlWznmFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMFILLISTDATA) {
			*dpcheng = new PnlWznmFilList::DpchEngData();
			((PnlWznmFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMFILRECDATA) {
			*dpcheng = new PnlWznmFilRec::DpchEngData();
			((PnlWznmFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIELDATA) {
			*dpcheng = new CrdWznmIel::DpchEngData();
			((CrdWznmIel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIELDETAILDATA) {
			*dpcheng = new PnlWznmIelDetail::DpchEngData();
			((PnlWznmIelDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIELHEADBARDATA) {
			*dpcheng = new PnlWznmIelHeadbar::DpchEngData();
			((PnlWznmIelHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIELLISTDATA) {
			*dpcheng = new PnlWznmIelList::DpchEngData();
			((PnlWznmIelList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIELRECDATA) {
			*dpcheng = new PnlWznmIelRec::DpchEngData();
			((PnlWznmIelRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEX1NIMPEXPDATA) {
			*dpcheng = new PnlWznmIex1NImpexp::DpchEngData();
			((PnlWznmIex1NImpexp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXDATA) {
			*dpcheng = new CrdWznmIex::DpchEngData();
			((CrdWznmIex::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXDETAILDATA) {
			*dpcheng = new PnlWznmIexDetail::DpchEngData();
			((PnlWznmIexDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXHEADBARDATA) {
			*dpcheng = new PnlWznmIexHeadbar::DpchEngData();
			((PnlWznmIexHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXHK1NVECTORDATA) {
			*dpcheng = new PnlWznmIexHk1NVector::DpchEngData();
			((PnlWznmIexHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXLISTDATA) {
			*dpcheng = new PnlWznmIexList::DpchEngData();
			((PnlWznmIexList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXRECDATA) {
			*dpcheng = new PnlWznmIexRec::DpchEngData();
			((PnlWznmIexRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIEXREF1NDIALOGDATA) {
			*dpcheng = new PnlWznmIexRef1NDialog::DpchEngData();
			((PnlWznmIexRef1NDialog::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMEDATA) {
			*dpcheng = new CrdWznmIme::DpchEngData();
			((CrdWznmIme::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMEDETAILDATA) {
			*dpcheng = new PnlWznmImeDetail::DpchEngData();
			((PnlWznmImeDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMEHEADBARDATA) {
			*dpcheng = new PnlWznmImeHeadbar::DpchEngData();
			((PnlWznmImeHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMEHK1NVECTORDATA) {
			*dpcheng = new PnlWznmImeHk1NVector::DpchEngData();
			((PnlWznmImeHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMEIME1NIMPEXPCOLDATA) {
			*dpcheng = new PnlWznmImeIme1NImpexpcol::DpchEngData();
			((PnlWznmImeIme1NImpexpcol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMELISTDATA) {
			*dpcheng = new PnlWznmImeList::DpchEngData();
			((PnlWznmImeList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMERECDATA) {
			*dpcheng = new PnlWznmImeRec::DpchEngData();
			((PnlWznmImeRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMIMESUP1NIMPEXPDATA) {
			*dpcheng = new PnlWznmImeSup1NImpexp::DpchEngData();
			((PnlWznmImeSup1NImpexp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOB1NMETHODDATA) {
			*dpcheng = new PnlWznmJob1NMethod::DpchEngData();
			((PnlWznmJob1NMethod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOB1NRTJOBDATA) {
			*dpcheng = new PnlWznmJob1NRtjob::DpchEngData();
			((PnlWznmJob1NRtjob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOB1NSENSITIVITYDATA) {
			*dpcheng = new PnlWznmJob1NSensitivity::DpchEngData();
			((PnlWznmJob1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBACMDDATA) {
			*dpcheng = new PnlWznmJobACmd::DpchEngData();
			((PnlWznmJobACmd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBAVARDATA) {
			*dpcheng = new PnlWznmJobAVar::DpchEngData();
			((PnlWznmJobAVar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBDATA) {
			*dpcheng = new CrdWznmJob::DpchEngData();
			((CrdWznmJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBDETAILDATA) {
			*dpcheng = new PnlWznmJobDetail::DpchEngData();
			((PnlWznmJobDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBHEADBARDATA) {
			*dpcheng = new PnlWznmJobHeadbar::DpchEngData();
			((PnlWznmJobHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBHK1NVECTORDATA) {
			*dpcheng = new PnlWznmJobHk1NVector::DpchEngData();
			((PnlWznmJobHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBJOB1NSTAGEDATA) {
			*dpcheng = new PnlWznmJobJob1NStage::DpchEngData();
			((PnlWznmJobJob1NStage::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBLISTDATA) {
			*dpcheng = new PnlWznmJobList::DpchEngData();
			((PnlWznmJobList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBMNOPDATA) {
			*dpcheng = new PnlWznmJobMNOp::DpchEngData();
			((PnlWznmJobMNOp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBMNOPPACKDATA) {
			*dpcheng = new PnlWznmJobMNOppack::DpchEngData();
			((PnlWznmJobMNOppack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBRECDATA) {
			*dpcheng = new PnlWznmJobRec::DpchEngData();
			((PnlWznmJobRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBREF1NBLOCKDATA) {
			*dpcheng = new PnlWznmJobRef1NBlock::DpchEngData();
			((PnlWznmJobRef1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBSUBMNJOBDATA) {
			*dpcheng = new PnlWznmJobSubMNJob::DpchEngData();
			((PnlWznmJobSubMNJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMJOBSUPMNJOBDATA) {
			*dpcheng = new PnlWznmJobSupMNJob::DpchEngData();
			((PnlWznmJobSupMNJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBAMAKEFILEDATA) {
			*dpcheng = new PnlWznmLibAMakefile::DpchEngData();
			((PnlWznmLibAMakefile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBAPKGLISTDATA) {
			*dpcheng = new PnlWznmLibAPkglist::DpchEngData();
			((PnlWznmLibAPkglist::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBDATA) {
			*dpcheng = new CrdWznmLib::DpchEngData();
			((CrdWznmLib::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBDETAILDATA) {
			*dpcheng = new PnlWznmLibDetail::DpchEngData();
			((PnlWznmLibDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBHEADBARDATA) {
			*dpcheng = new PnlWznmLibHeadbar::DpchEngData();
			((PnlWznmLibHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBLISTDATA) {
			*dpcheng = new PnlWznmLibList::DpchEngData();
			((PnlWznmLibList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBMNCOMPONENTDATA) {
			*dpcheng = new PnlWznmLibMNComponent::DpchEngData();
			((PnlWznmLibMNComponent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBMNOPPACKDATA) {
			*dpcheng = new PnlWznmLibMNOppack::DpchEngData();
			((PnlWznmLibMNOppack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBRECDATA) {
			*dpcheng = new PnlWznmLibRec::DpchEngData();
			((PnlWznmLibRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLIBREF1NFILEDATA) {
			*dpcheng = new PnlWznmLibRef1NFile::DpchEngData();
			((PnlWznmLibRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCDATA) {
			*dpcheng = new CrdWznmLoc::DpchEngData();
			((CrdWznmLoc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCDETAILDATA) {
			*dpcheng = new PnlWznmLocDetail::DpchEngData();
			((PnlWznmLocDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCHEADBARDATA) {
			*dpcheng = new PnlWznmLocHeadbar::DpchEngData();
			((PnlWznmLocHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCLISTDATA) {
			*dpcheng = new PnlWznmLocList::DpchEngData();
			((PnlWznmLocList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCMNVERSIONDATA) {
			*dpcheng = new PnlWznmLocMNVersion::DpchEngData();
			((PnlWznmLocMNVersion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMLOCRECDATA) {
			*dpcheng = new PnlWznmLocRec::DpchEngData();
			((PnlWznmLocRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCH1NRELEASEDATA) {
			*dpcheng = new PnlWznmMch1NRelease::DpchEngData();
			((PnlWznmMch1NRelease::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHAMAKEFILEDATA) {
			*dpcheng = new PnlWznmMchAMakefile::DpchEngData();
			((PnlWznmMchAMakefile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHAPARDATA) {
			*dpcheng = new PnlWznmMchAPar::DpchEngData();
			((PnlWznmMchAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHDATA) {
			*dpcheng = new CrdWznmMch::DpchEngData();
			((CrdWznmMch::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHDETAILDATA) {
			*dpcheng = new PnlWznmMchDetail::DpchEngData();
			((PnlWznmMchDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHHEADBARDATA) {
			*dpcheng = new PnlWznmMchHeadbar::DpchEngData();
			((PnlWznmMchHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHLISTDATA) {
			*dpcheng = new PnlWznmMchList::DpchEngData();
			((PnlWznmMchList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHRECDATA) {
			*dpcheng = new PnlWznmMchRec::DpchEngData();
			((PnlWznmMchRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMCHSUP1NMACHINEDATA) {
			*dpcheng = new PnlWznmMchSup1NMachine::DpchEngData();
			((PnlWznmMchSup1NMachine::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLDATA) {
			*dpcheng = new CrdWznmMdl::DpchEngData();
			((CrdWznmMdl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLDETAILDATA) {
			*dpcheng = new PnlWznmMdlDetail::DpchEngData();
			((PnlWznmMdlDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLHEADBARDATA) {
			*dpcheng = new PnlWznmMdlHeadbar::DpchEngData();
			((PnlWznmMdlHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLLISTDATA) {
			*dpcheng = new PnlWznmMdlList::DpchEngData();
			((PnlWznmMdlList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLMDL1NCARDDATA) {
			*dpcheng = new PnlWznmMdlMdl1NCard::DpchEngData();
			((PnlWznmMdlMdl1NCard::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLRECDATA) {
			*dpcheng = new PnlWznmMdlRec::DpchEngData();
			((PnlWznmMdlRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMDLREF1NPANELDATA) {
			*dpcheng = new PnlWznmMdlRef1NPanel::DpchEngData();
			((PnlWznmMdlRef1NPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDAINVPARDATA) {
			*dpcheng = new PnlWznmMtdAInvpar::DpchEngData();
			((PnlWznmMtdAInvpar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDARETPARDATA) {
			*dpcheng = new PnlWznmMtdARetpar::DpchEngData();
			((PnlWznmMtdARetpar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDDATA) {
			*dpcheng = new CrdWznmMtd::DpchEngData();
			((CrdWznmMtd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDDETAILDATA) {
			*dpcheng = new PnlWznmMtdDetail::DpchEngData();
			((PnlWznmMtdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDHEADBARDATA) {
			*dpcheng = new PnlWznmMtdHeadbar::DpchEngData();
			((PnlWznmMtdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDLISTDATA) {
			*dpcheng = new PnlWznmMtdList::DpchEngData();
			((PnlWznmMtdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMMTDRECDATA) {
			*dpcheng = new PnlWznmMtdRec::DpchEngData();
			((PnlWznmMtdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVADMINDATA) {
			*dpcheng = new PnlWznmNavAdmin::DpchEngData();
			((PnlWznmNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVAPPDEVDATA) {
			*dpcheng = new PnlWznmNavAppdev::DpchEngData();
			((PnlWznmNavAppdev::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVAUXFCTDATA) {
			*dpcheng = new PnlWznmNavAuxfct::DpchEngData();
			((PnlWznmNavAuxfct::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVCOMPDATA) {
			*dpcheng = new PnlWznmNavComp::DpchEngData();
			((PnlWznmNavComp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVDATA) {
			*dpcheng = new CrdWznmNav::DpchEngData();
			((CrdWznmNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVDBSTRDATA) {
			*dpcheng = new PnlWznmNavDbstr::DpchEngData();
			((PnlWznmNavDbstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVDEPLOYDATA) {
			*dpcheng = new PnlWznmNavDeploy::DpchEngData();
			((PnlWznmNavDeploy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVGLOBALDATA) {
			*dpcheng = new PnlWznmNavGlobal::DpchEngData();
			((PnlWznmNavGlobal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVHEADBARDATA) {
			*dpcheng = new PnlWznmNavHeadbar::DpchEngData();
			((PnlWznmNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVJOBDATA) {
			*dpcheng = new PnlWznmNavJob::DpchEngData();
			((PnlWznmNavJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVPREDATA) {
			*dpcheng = new PnlWznmNavPre::DpchEngData();
			((PnlWznmNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVPROJECTDATA) {
			*dpcheng = new PnlWznmNavProject::DpchEngData();
			((PnlWznmNavProject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVUIXDATA) {
			*dpcheng = new PnlWznmNavUix::DpchEngData();
			((PnlWznmNavUix::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMNAVVISUALDATA) {
			*dpcheng = new PnlWznmNavVisual::DpchEngData();
			((PnlWznmNavVisual::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPK1NOPDATA) {
			*dpcheng = new PnlWznmOpk1NOp::DpchEngData();
			((PnlWznmOpk1NOp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKAINVARGDATA) {
			*dpcheng = new PnlWznmOpkAInvarg::DpchEngData();
			((PnlWznmOpkAInvarg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKARETVALDATA) {
			*dpcheng = new PnlWznmOpkARetval::DpchEngData();
			((PnlWznmOpkARetval::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKDATA) {
			*dpcheng = new CrdWznmOpk::DpchEngData();
			((CrdWznmOpk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKDETAILDATA) {
			*dpcheng = new PnlWznmOpkDetail::DpchEngData();
			((PnlWznmOpkDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKHEADBARDATA) {
			*dpcheng = new PnlWznmOpkHeadbar::DpchEngData();
			((PnlWznmOpkHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKLISTDATA) {
			*dpcheng = new PnlWznmOpkList::DpchEngData();
			((PnlWznmOpkList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKMNCOMPONENTDATA) {
			*dpcheng = new PnlWznmOpkMNComponent::DpchEngData();
			((PnlWznmOpkMNComponent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKMNJOBDATA) {
			*dpcheng = new PnlWznmOpkMNJob::DpchEngData();
			((PnlWznmOpkMNJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKMNLIBRARYDATA) {
			*dpcheng = new PnlWznmOpkMNLibrary::DpchEngData();
			((PnlWznmOpkMNLibrary::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKRECDATA) {
			*dpcheng = new PnlWznmOpkRec::DpchEngData();
			((PnlWznmOpkRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKREF1NBLOCKDATA) {
			*dpcheng = new PnlWznmOpkRef1NBlock::DpchEngData();
			((PnlWznmOpkRef1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPKSQKMNSTUBDATA) {
			*dpcheng = new PnlWznmOpkSqkMNStub::DpchEngData();
			((PnlWznmOpkSqkMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXAINVARGDATA) {
			*dpcheng = new PnlWznmOpxAInvarg::DpchEngData();
			((PnlWznmOpxAInvarg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXARETVALDATA) {
			*dpcheng = new PnlWznmOpxARetval::DpchEngData();
			((PnlWznmOpxARetval::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXDATA) {
			*dpcheng = new CrdWznmOpx::DpchEngData();
			((CrdWznmOpx::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXDETAILDATA) {
			*dpcheng = new PnlWznmOpxDetail::DpchEngData();
			((PnlWznmOpxDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXHEADBARDATA) {
			*dpcheng = new PnlWznmOpxHeadbar::DpchEngData();
			((PnlWznmOpxHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXLISTDATA) {
			*dpcheng = new PnlWznmOpxList::DpchEngData();
			((PnlWznmOpxList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXMNJOBDATA) {
			*dpcheng = new PnlWznmOpxMNJob::DpchEngData();
			((PnlWznmOpxMNJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXRECDATA) {
			*dpcheng = new PnlWznmOpxRec::DpchEngData();
			((PnlWznmOpxRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXREF1NBLOCKDATA) {
			*dpcheng = new PnlWznmOpxRef1NBlock::DpchEngData();
			((PnlWznmOpxRef1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMOPXSQKMNSTUBDATA) {
			*dpcheng = new PnlWznmOpxSqkMNStub::DpchEngData();
			((PnlWznmOpxSqkMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLDATA) {
			*dpcheng = new CrdWznmPnl::DpchEngData();
			((CrdWznmPnl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLDETAILDATA) {
			*dpcheng = new PnlWznmPnlDetail::DpchEngData();
			((PnlWznmPnlDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLHEADBARDATA) {
			*dpcheng = new PnlWznmPnlHeadbar::DpchEngData();
			((PnlWznmPnlHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLHK1NCONTROLDATA) {
			*dpcheng = new PnlWznmPnlHk1NControl::DpchEngData();
			((PnlWznmPnlHk1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLLISTDATA) {
			*dpcheng = new PnlWznmPnlList::DpchEngData();
			((PnlWznmPnlList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLMNQUERYDATA) {
			*dpcheng = new PnlWznmPnlMNQuery::DpchEngData();
			((PnlWznmPnlMNQuery::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPNLRECDATA) {
			*dpcheng = new PnlWznmPnlRec::DpchEngData();
			((PnlWznmPnlRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJDATA) {
			*dpcheng = new CrdWznmPrj::DpchEngData();
			((CrdWznmPrj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJDETAILDATA) {
			*dpcheng = new PnlWznmPrjDetail::DpchEngData();
			((PnlWznmPrjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJHEADBARDATA) {
			*dpcheng = new PnlWznmPrjHeadbar::DpchEngData();
			((PnlWznmPrjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJLISTDATA) {
			*dpcheng = new PnlWznmPrjList::DpchEngData();
			((PnlWznmPrjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJMNPERSONDATA) {
			*dpcheng = new PnlWznmPrjMNPerson::DpchEngData();
			((PnlWznmPrjMNPerson::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJPRJ1NVERSIONDATA) {
			*dpcheng = new PnlWznmPrjPrj1NVersion::DpchEngData();
			((PnlWznmPrjPrj1NVersion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRJRECDATA) {
			*dpcheng = new PnlWznmPrjRec::DpchEngData();
			((PnlWznmPrjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSADETAILDATA) {
			*dpcheng = new PnlWznmPrsADetail::DpchEngData();
			((PnlWznmPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSDATA) {
			*dpcheng = new CrdWznmPrs::DpchEngData();
			((CrdWznmPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSDETAILDATA) {
			*dpcheng = new PnlWznmPrsDetail::DpchEngData();
			((PnlWznmPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSHEADBARDATA) {
			*dpcheng = new PnlWznmPrsHeadbar::DpchEngData();
			((PnlWznmPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSLISTDATA) {
			*dpcheng = new PnlWznmPrsList::DpchEngData();
			((PnlWznmPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSMNPROJECTDATA) {
			*dpcheng = new PnlWznmPrsMNProject::DpchEngData();
			((PnlWznmPrsMNProject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPRSRECDATA) {
			*dpcheng = new PnlWznmPrsRec::DpchEngData();
			((PnlWznmPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPST1NQUERYMODDATA) {
			*dpcheng = new PnlWznmPst1NQuerymod::DpchEngData();
			((PnlWznmPst1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPSTDATA) {
			*dpcheng = new CrdWznmPst::DpchEngData();
			((CrdWznmPst::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPSTDETAILDATA) {
			*dpcheng = new PnlWznmPstDetail::DpchEngData();
			((PnlWznmPstDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPSTHEADBARDATA) {
			*dpcheng = new PnlWznmPstHeadbar::DpchEngData();
			((PnlWznmPstHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPSTLISTDATA) {
			*dpcheng = new PnlWznmPstList::DpchEngData();
			((PnlWznmPstList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMPSTRECDATA) {
			*dpcheng = new PnlWznmPstRec::DpchEngData();
			((PnlWznmPstRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCODATA) {
			*dpcheng = new CrdWznmQco::DpchEngData();
			((CrdWznmQco::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCODETAILDATA) {
			*dpcheng = new PnlWznmQcoDetail::DpchEngData();
			((PnlWznmQcoDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCOHEADBARDATA) {
			*dpcheng = new PnlWznmQcoHeadbar::DpchEngData();
			((PnlWznmQcoHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCOLISTDATA) {
			*dpcheng = new PnlWznmQcoList::DpchEngData();
			((PnlWznmQcoList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCORECDATA) {
			*dpcheng = new PnlWznmQcoRec::DpchEngData();
			((PnlWznmQcoRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQCOREF1NCONTROLDATA) {
			*dpcheng = new PnlWznmQcoRef1NControl::DpchEngData();
			((PnlWznmQcoRef1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQMDDATA) {
			*dpcheng = new CrdWznmQmd::DpchEngData();
			((CrdWznmQmd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQMDDETAILDATA) {
			*dpcheng = new PnlWznmQmdDetail::DpchEngData();
			((PnlWznmQmdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQMDHEADBARDATA) {
			*dpcheng = new PnlWznmQmdHeadbar::DpchEngData();
			((PnlWznmQmdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQMDLISTDATA) {
			*dpcheng = new PnlWznmQmdList::DpchEngData();
			((PnlWznmQmdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQMDRECDATA) {
			*dpcheng = new PnlWznmQmdRec::DpchEngData();
			((PnlWznmQmdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRY1NQUERYMODDATA) {
			*dpcheng = new PnlWznmQry1NQuerymod::DpchEngData();
			((PnlWznmQry1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYACLAUSEDATA) {
			*dpcheng = new PnlWznmQryAClause::DpchEngData();
			((PnlWznmQryAClause::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYAORDERDATA) {
			*dpcheng = new PnlWznmQryAOrder::DpchEngData();
			((PnlWznmQryAOrder::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYDATA) {
			*dpcheng = new CrdWznmQry::DpchEngData();
			((CrdWznmQry::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYDETAILDATA) {
			*dpcheng = new PnlWznmQryDetail::DpchEngData();
			((PnlWznmQryDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYHEADBARDATA) {
			*dpcheng = new PnlWznmQryHeadbar::DpchEngData();
			((PnlWznmQryHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYLISTDATA) {
			*dpcheng = new PnlWznmQryList::DpchEngData();
			((PnlWznmQryList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYMNDIALOGDATA) {
			*dpcheng = new PnlWznmQryMNDialog::DpchEngData();
			((PnlWznmQryMNDialog::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYMNPANELDATA) {
			*dpcheng = new PnlWznmQryMNPanel::DpchEngData();
			((PnlWznmQryMNPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYMNTABLEDATA) {
			*dpcheng = new PnlWznmQryMNTable::DpchEngData();
			((PnlWznmQryMNTable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYQRY1NQUERYCOLDATA) {
			*dpcheng = new PnlWznmQryQry1NQuerycol::DpchEngData();
			((PnlWznmQryQry1NQuerycol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYRECDATA) {
			*dpcheng = new PnlWznmQryRec::DpchEngData();
			((PnlWznmQryRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMQRYSUP1NQUERYDATA) {
			*dpcheng = new PnlWznmQrySup1NQuery::DpchEngData();
			((PnlWznmQrySup1NQuery::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMREL1NTABLECOLDATA) {
			*dpcheng = new PnlWznmRel1NTablecol::DpchEngData();
			((PnlWznmRel1NTablecol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELATITLEDATA) {
			*dpcheng = new PnlWznmRelATitle::DpchEngData();
			((PnlWznmRelATitle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELDATA) {
			*dpcheng = new CrdWznmRel::DpchEngData();
			((CrdWznmRel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELDETAILDATA) {
			*dpcheng = new PnlWznmRelDetail::DpchEngData();
			((PnlWznmRelDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELHEADBARDATA) {
			*dpcheng = new PnlWznmRelHeadbar::DpchEngData();
			((PnlWznmRelHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELLISTDATA) {
			*dpcheng = new PnlWznmRelList::DpchEngData();
			((PnlWznmRelList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELRECDATA) {
			*dpcheng = new PnlWznmRelRec::DpchEngData();
			((PnlWznmRelRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELREF1NCONTROLDATA) {
			*dpcheng = new PnlWznmRelRef1NControl::DpchEngData();
			((PnlWznmRelRef1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELREF1NDIALOGDATA) {
			*dpcheng = new PnlWznmRelRef1NDialog::DpchEngData();
			((PnlWznmRelRef1NDialog::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELREF1NPANELDATA) {
			*dpcheng = new PnlWznmRelRef1NPanel::DpchEngData();
			((PnlWznmRelRef1NPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRELSUP1NRELATIONDATA) {
			*dpcheng = new PnlWznmRelSup1NRelation::DpchEngData();
			((PnlWznmRelSup1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRLSDATA) {
			*dpcheng = new CrdWznmRls::DpchEngData();
			((CrdWznmRls::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRLSDETAILDATA) {
			*dpcheng = new PnlWznmRlsDetail::DpchEngData();
			((PnlWznmRlsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRLSHEADBARDATA) {
			*dpcheng = new PnlWznmRlsHeadbar::DpchEngData();
			((PnlWznmRlsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRLSLISTDATA) {
			*dpcheng = new PnlWznmRlsList::DpchEngData();
			((PnlWznmRlsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRLSRECDATA) {
			*dpcheng = new PnlWznmRlsRec::DpchEngData();
			((PnlWznmRlsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJ1NRTBLOCKDATA) {
			*dpcheng = new PnlWznmRtj1NRtblock::DpchEngData();
			((PnlWznmRtj1NRtblock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJ1NRTDPCHDATA) {
			*dpcheng = new PnlWznmRtj1NRtdpch::DpchEngData();
			((PnlWznmRtj1NRtdpch::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJDATA) {
			*dpcheng = new CrdWznmRtj::DpchEngData();
			((CrdWznmRtj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJDETAILDATA) {
			*dpcheng = new PnlWznmRtjDetail::DpchEngData();
			((PnlWznmRtjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJHEADBARDATA) {
			*dpcheng = new PnlWznmRtjHeadbar::DpchEngData();
			((PnlWznmRtjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJLISTDATA) {
			*dpcheng = new PnlWznmRtjList::DpchEngData();
			((PnlWznmRtjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJRECDATA) {
			*dpcheng = new PnlWznmRtjRec::DpchEngData();
			((PnlWznmRtjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMRTJSUP1NRTJOBDATA) {
			*dpcheng = new PnlWznmRtjSup1NRtjob::DpchEngData();
			((PnlWznmRtjSup1NRtjob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBS1NSTUBDATA) {
			*dpcheng = new PnlWznmSbs1NStub::DpchEngData();
			((PnlWznmSbs1NStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBS1NTABLECOLDATA) {
			*dpcheng = new PnlWznmSbs1NTablecol::DpchEngData();
			((PnlWznmSbs1NTablecol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSASBMNSUBSETDATA) {
			*dpcheng = new PnlWznmSbsAsbMNSubset::DpchEngData();
			((PnlWznmSbsAsbMNSubset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSATITLEDATA) {
			*dpcheng = new PnlWznmSbsATitle::DpchEngData();
			((PnlWznmSbsATitle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSBSBMNSUBSETDATA) {
			*dpcheng = new PnlWznmSbsBsbMNSubset::DpchEngData();
			((PnlWznmSbsBsbMNSubset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSDATA) {
			*dpcheng = new CrdWznmSbs::DpchEngData();
			((CrdWznmSbs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSDETAILDATA) {
			*dpcheng = new PnlWznmSbsDetail::DpchEngData();
			((PnlWznmSbsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSFRS1NRELATIONDATA) {
			*dpcheng = new PnlWznmSbsFrs1NRelation::DpchEngData();
			((PnlWznmSbsFrs1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSHEADBARDATA) {
			*dpcheng = new PnlWznmSbsHeadbar::DpchEngData();
			((PnlWznmSbsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSLISTDATA) {
			*dpcheng = new PnlWznmSbsList::DpchEngData();
			((PnlWznmSbsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSPST1NQUERYMODDATA) {
			*dpcheng = new PnlWznmSbsPst1NQuerymod::DpchEngData();
			((PnlWznmSbsPst1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSRECDATA) {
			*dpcheng = new PnlWznmSbsRec::DpchEngData();
			((PnlWznmSbsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSBSTOS1NRELATIONDATA) {
			*dpcheng = new PnlWznmSbsTos1NRelation::DpchEngData();
			((PnlWznmSbsTos1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQDATA) {
			*dpcheng = new CrdWznmSeq::DpchEngData();
			((CrdWznmSeq::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQDETAILDATA) {
			*dpcheng = new PnlWznmSeqDetail::DpchEngData();
			((PnlWznmSeqDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQHEADBARDATA) {
			*dpcheng = new PnlWznmSeqHeadbar::DpchEngData();
			((PnlWznmSeqHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQLISTDATA) {
			*dpcheng = new PnlWznmSeqList::DpchEngData();
			((PnlWznmSeqList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQRECDATA) {
			*dpcheng = new PnlWznmSeqRec::DpchEngData();
			((PnlWznmSeqRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSEQSEQ1NSTATEDATA) {
			*dpcheng = new PnlWznmSeqSeq1NState::DpchEngData();
			((PnlWznmSeqSeq1NState::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGE1NSENSITIVITYDATA) {
			*dpcheng = new PnlWznmSge1NSensitivity::DpchEngData();
			((PnlWznmSge1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGEDATA) {
			*dpcheng = new CrdWznmSge::DpchEngData();
			((CrdWznmSge::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGEDETAILDATA) {
			*dpcheng = new PnlWznmSgeDetail::DpchEngData();
			((PnlWznmSgeDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGEHEADBARDATA) {
			*dpcheng = new PnlWznmSgeHeadbar::DpchEngData();
			((PnlWznmSgeHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGELISTDATA) {
			*dpcheng = new PnlWznmSgeList::DpchEngData();
			((PnlWznmSgeList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGERECDATA) {
			*dpcheng = new PnlWznmSgeRec::DpchEngData();
			((PnlWznmSgeRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSGESQKMNSTUBDATA) {
			*dpcheng = new PnlWznmSgeSqkMNStub::DpchEngData();
			((PnlWznmSgeSqkMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHT1NBOXDATA) {
			*dpcheng = new PnlWznmSht1NBox::DpchEngData();
			((PnlWznmSht1NBox::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHTDATA) {
			*dpcheng = new CrdWznmSht::DpchEngData();
			((CrdWznmSht::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHTDETAILDATA) {
			*dpcheng = new PnlWznmShtDetail::DpchEngData();
			((PnlWznmShtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHTHEADBARDATA) {
			*dpcheng = new PnlWznmShtHeadbar::DpchEngData();
			((PnlWznmShtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHTLISTDATA) {
			*dpcheng = new PnlWznmShtList::DpchEngData();
			((PnlWznmShtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSHTRECDATA) {
			*dpcheng = new PnlWznmShtRec::DpchEngData();
			((PnlWznmShtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBDATA) {
			*dpcheng = new CrdWznmStb::DpchEngData();
			((CrdWznmStb::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBDETAILDATA) {
			*dpcheng = new PnlWznmStbDetail::DpchEngData();
			((PnlWznmStbDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBHEADBARDATA) {
			*dpcheng = new PnlWznmStbHeadbar::DpchEngData();
			((PnlWznmStbHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBLISTDATA) {
			*dpcheng = new PnlWznmStbList::DpchEngData();
			((PnlWznmStbList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBMNCALLDATA) {
			*dpcheng = new PnlWznmStbMNCall::DpchEngData();
			((PnlWznmStbMNCall::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBMNSQUAWKDATA) {
			*dpcheng = new PnlWznmStbMNSquawk::DpchEngData();
			((PnlWznmStbMNSquawk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBRECDATA) {
			*dpcheng = new PnlWznmStbRec::DpchEngData();
			((PnlWznmStbRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBSUBMNSTUBDATA) {
			*dpcheng = new PnlWznmStbSubMNStub::DpchEngData();
			((PnlWznmStbSubMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTBSUPMNSTUBDATA) {
			*dpcheng = new PnlWznmStbSupMNStub::DpchEngData();
			((PnlWznmStbSupMNStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTEAACTIONDATA) {
			*dpcheng = new PnlWznmSteAAction::DpchEngData();
			((PnlWznmSteAAction::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTEATRIGDATA) {
			*dpcheng = new PnlWznmSteATrig::DpchEngData();
			((PnlWznmSteATrig::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTEDATA) {
			*dpcheng = new CrdWznmSte::DpchEngData();
			((CrdWznmSte::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTEDETAILDATA) {
			*dpcheng = new PnlWznmSteDetail::DpchEngData();
			((PnlWznmSteDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTEHEADBARDATA) {
			*dpcheng = new PnlWznmSteHeadbar::DpchEngData();
			((PnlWznmSteHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTELISTDATA) {
			*dpcheng = new PnlWznmSteList::DpchEngData();
			((PnlWznmSteList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSTERECDATA) {
			*dpcheng = new PnlWznmSteRec::DpchEngData();
			((PnlWznmSteRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMSUSPEND) {
			*dpcheng = new DpchEngWznmSuspend();
			((DpchEngWznmSuspend*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTAGDATA) {
			*dpcheng = new CrdWznmTag::DpchEngData();
			((CrdWznmTag::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTAGDETAILDATA) {
			*dpcheng = new PnlWznmTagDetail::DpchEngData();
			((PnlWznmTagDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTAGHEADBARDATA) {
			*dpcheng = new PnlWznmTagHeadbar::DpchEngData();
			((PnlWznmTagHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTAGLISTDATA) {
			*dpcheng = new PnlWznmTagList::DpchEngData();
			((PnlWznmTagList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTAGRECDATA) {
			*dpcheng = new PnlWznmTagRec::DpchEngData();
			((PnlWznmTagRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBL1NCHECKDATA) {
			*dpcheng = new PnlWznmTbl1NCheck::DpchEngData();
			((PnlWznmTbl1NCheck::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBL1NIMPEXPDATA) {
			*dpcheng = new PnlWznmTbl1NImpexp::DpchEngData();
			((PnlWznmTbl1NImpexp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBL1NSTUBDATA) {
			*dpcheng = new PnlWznmTbl1NStub::DpchEngData();
			((PnlWznmTbl1NStub::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBL1NSUBSETDATA) {
			*dpcheng = new PnlWznmTbl1NSubset::DpchEngData();
			((PnlWznmTbl1NSubset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLALOADFCTDATA) {
			*dpcheng = new PnlWznmTblALoadfct::DpchEngData();
			((PnlWznmTblALoadfct::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLATITLEDATA) {
			*dpcheng = new PnlWznmTblATitle::DpchEngData();
			((PnlWznmTblATitle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLDATA) {
			*dpcheng = new CrdWznmTbl::DpchEngData();
			((CrdWznmTbl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLDETAILDATA) {
			*dpcheng = new PnlWznmTblDetail::DpchEngData();
			((PnlWznmTblDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLFCT1NTABLECOLDATA) {
			*dpcheng = new PnlWznmTblFct1NTablecol::DpchEngData();
			((PnlWznmTblFct1NTablecol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLFR1NRELATIONDATA) {
			*dpcheng = new PnlWznmTblFr1NRelation::DpchEngData();
			((PnlWznmTblFr1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLHEADBARDATA) {
			*dpcheng = new PnlWznmTblHeadbar::DpchEngData();
			((PnlWznmTblHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLHK1NVECTORDATA) {
			*dpcheng = new PnlWznmTblHk1NVector::DpchEngData();
			((PnlWznmTblHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLLISTDATA) {
			*dpcheng = new PnlWznmTblList::DpchEngData();
			((PnlWznmTblList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLMNQUERYDATA) {
			*dpcheng = new PnlWznmTblMNQuery::DpchEngData();
			((PnlWznmTblMNQuery::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLMNVECTORDATA) {
			*dpcheng = new PnlWznmTblMNVector::DpchEngData();
			((PnlWznmTblMNVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLPST1NQUERYMODDATA) {
			*dpcheng = new PnlWznmTblPst1NQuerymod::DpchEngData();
			((PnlWznmTblPst1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLRECDATA) {
			*dpcheng = new PnlWznmTblRec::DpchEngData();
			((PnlWznmTblRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLREF1NCALLDATA) {
			*dpcheng = new PnlWznmTblRef1NCall::DpchEngData();
			((PnlWznmTblRef1NCall::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLREF1NDIALOGDATA) {
			*dpcheng = new PnlWznmTblRef1NDialog::DpchEngData();
			((PnlWznmTblRef1NDialog::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLREF1NPANELDATA) {
			*dpcheng = new PnlWznmTblRef1NPanel::DpchEngData();
			((PnlWznmTblRef1NPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLREF1NQUERYMODDATA) {
			*dpcheng = new PnlWznmTblRef1NQuerymod::DpchEngData();
			((PnlWznmTblRef1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLREF1NRTBLOCKDATA) {
			*dpcheng = new PnlWznmTblRef1NRtblock::DpchEngData();
			((PnlWznmTblRef1NRtblock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLSRC1NFEEDDATA) {
			*dpcheng = new PnlWznmTblSrc1NFeed::DpchEngData();
			((PnlWznmTblSrc1NFeed::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLTBL1NTABLECOLDATA) {
			*dpcheng = new PnlWznmTblTbl1NTablecol::DpchEngData();
			((PnlWznmTblTbl1NTablecol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTBLTO1NRELATIONDATA) {
			*dpcheng = new PnlWznmTblTo1NRelation::DpchEngData();
			((PnlWznmTblTo1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCO1NCHECKDATA) {
			*dpcheng = new PnlWznmTco1NCheck::DpchEngData();
			((PnlWznmTco1NCheck::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCO1NIMPEXPCOLDATA) {
			*dpcheng = new PnlWznmTco1NImpexpcol::DpchEngData();
			((PnlWznmTco1NImpexpcol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCO1NQUERYCOLDATA) {
			*dpcheng = new PnlWznmTco1NQuerycol::DpchEngData();
			((PnlWznmTco1NQuerycol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCOATITLEDATA) {
			*dpcheng = new PnlWznmTcoATitle::DpchEngData();
			((PnlWznmTcoATitle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCODATA) {
			*dpcheng = new CrdWznmTco::DpchEngData();
			((CrdWznmTco::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCODETAILDATA) {
			*dpcheng = new PnlWznmTcoDetail::DpchEngData();
			((PnlWznmTcoDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCOHEADBARDATA) {
			*dpcheng = new PnlWznmTcoHeadbar::DpchEngData();
			((PnlWznmTcoHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCOLISTDATA) {
			*dpcheng = new PnlWznmTcoList::DpchEngData();
			((PnlWznmTcoList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCORECDATA) {
			*dpcheng = new PnlWznmTcoRec::DpchEngData();
			((PnlWznmTcoRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCOREF1NCONTROLDATA) {
			*dpcheng = new PnlWznmTcoRef1NControl::DpchEngData();
			((PnlWznmTcoRef1NControl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMTCOREF1NQUERYMODDATA) {
			*dpcheng = new PnlWznmTcoRef1NQuerymod::DpchEngData();
			((PnlWznmTcoRef1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGAACCESSDATA) {
			*dpcheng = new PnlWznmUsgAAccess::DpchEngData();
			((PnlWznmUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGDATA) {
			*dpcheng = new CrdWznmUsg::DpchEngData();
			((CrdWznmUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGDETAILDATA) {
			*dpcheng = new PnlWznmUsgDetail::DpchEngData();
			((PnlWznmUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGHEADBARDATA) {
			*dpcheng = new PnlWznmUsgHeadbar::DpchEngData();
			((PnlWznmUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGLISTDATA) {
			*dpcheng = new PnlWznmUsgList::DpchEngData();
			((PnlWznmUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGMNUSERDATA) {
			*dpcheng = new PnlWznmUsgMNUser::DpchEngData();
			((PnlWznmUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSGRECDATA) {
			*dpcheng = new PnlWznmUsgRec::DpchEngData();
			((PnlWznmUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSR1NSESSIONDATA) {
			*dpcheng = new PnlWznmUsr1NSession::DpchEngData();
			((PnlWznmUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRAACCESSDATA) {
			*dpcheng = new PnlWznmUsrAAccess::DpchEngData();
			((PnlWznmUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRDATA) {
			*dpcheng = new CrdWznmUsr::DpchEngData();
			((CrdWznmUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRDETAILDATA) {
			*dpcheng = new PnlWznmUsrDetail::DpchEngData();
			((PnlWznmUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRHEADBARDATA) {
			*dpcheng = new PnlWznmUsrHeadbar::DpchEngData();
			((PnlWznmUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRLISTDATA) {
			*dpcheng = new PnlWznmUsrList::DpchEngData();
			((PnlWznmUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRMNUSERGROUPDATA) {
			*dpcheng = new PnlWznmUsrMNUsergroup::DpchEngData();
			((PnlWznmUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUSRRECDATA) {
			*dpcheng = new PnlWznmUsrRec::DpchEngData();
			((PnlWznmUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUTLDATA) {
			*dpcheng = new CrdWznmUtl::DpchEngData();
			((CrdWznmUtl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMUTLHEADBARDATA) {
			*dpcheng = new PnlWznmUtlHeadbar::DpchEngData();
			((PnlWznmUtlHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECATITLEDATA) {
			*dpcheng = new PnlWznmVecATitle::DpchEngData();
			((PnlWznmVecATitle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECDATA) {
			*dpcheng = new CrdWznmVec::DpchEngData();
			((CrdWznmVec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECDETAILDATA) {
			*dpcheng = new PnlWznmVecDetail::DpchEngData();
			((PnlWznmVecDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECFCT1NTABLECOLDATA) {
			*dpcheng = new PnlWznmVecFct1NTablecol::DpchEngData();
			((PnlWznmVecFct1NTablecol::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECHEADBARDATA) {
			*dpcheng = new PnlWznmVecHeadbar::DpchEngData();
			((PnlWznmVecHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECLISTDATA) {
			*dpcheng = new PnlWznmVecList::DpchEngData();
			((PnlWznmVecList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECMNTABLEDATA) {
			*dpcheng = new PnlWznmVecMNTable::DpchEngData();
			((PnlWznmVecMNTable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECPST1NQUERYMODDATA) {
			*dpcheng = new PnlWznmVecPst1NQuerymod::DpchEngData();
			((PnlWznmVecPst1NQuerymod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECRECDATA) {
			*dpcheng = new PnlWznmVecRec::DpchEngData();
			((PnlWznmVecRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECREF1NPANELDATA) {
			*dpcheng = new PnlWznmVecRef1NPanel::DpchEngData();
			((PnlWznmVecRef1NPanel::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECSRC1NFEEDDATA) {
			*dpcheng = new PnlWznmVecSrc1NFeed::DpchEngData();
			((PnlWznmVecSrc1NFeed::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVECVEC1NVECTORITEMDATA) {
			*dpcheng = new PnlWznmVecVec1NVectoritem::DpchEngData();
			((PnlWznmVecVec1NVectoritem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NBLOCKDATA) {
			*dpcheng = new PnlWznmVer1NBlock::DpchEngData();
			((PnlWznmVer1NBlock::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NCALLDATA) {
			*dpcheng = new PnlWznmVer1NCall::DpchEngData();
			((PnlWznmVer1NCall::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NCAPABILITYDATA) {
			*dpcheng = new PnlWznmVer1NCapability::DpchEngData();
			((PnlWznmVer1NCapability::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NCOMPONENTDATA) {
			*dpcheng = new PnlWznmVer1NComponent::DpchEngData();
			((PnlWznmVer1NComponent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NIMPEXPCPLXDATA) {
			*dpcheng = new PnlWznmVer1NImpexpcplx::DpchEngData();
			((PnlWznmVer1NImpexpcplx::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NJOBDATA) {
			*dpcheng = new PnlWznmVer1NJob::DpchEngData();
			((PnlWznmVer1NJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NOPPACKDATA) {
			*dpcheng = new PnlWznmVer1NOppack::DpchEngData();
			((PnlWznmVer1NOppack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NPRESETDATA) {
			*dpcheng = new PnlWznmVer1NPreset::DpchEngData();
			((PnlWznmVer1NPreset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NQUERYDATA) {
			*dpcheng = new PnlWznmVer1NQuery::DpchEngData();
			((PnlWznmVer1NQuery::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NRELATIONDATA) {
			*dpcheng = new PnlWznmVer1NRelation::DpchEngData();
			((PnlWznmVer1NRelation::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NTABLEDATA) {
			*dpcheng = new PnlWznmVer1NTable::DpchEngData();
			((PnlWznmVer1NTable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVER1NVECTORDATA) {
			*dpcheng = new PnlWznmVer1NVector::DpchEngData();
			((PnlWznmVer1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERBVR1NVERSIONDATA) {
			*dpcheng = new PnlWznmVerBvr1NVersion::DpchEngData();
			((PnlWznmVerBvr1NVersion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERDATA) {
			*dpcheng = new CrdWznmVer::DpchEngData();
			((CrdWznmVer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERDETAILDATA) {
			*dpcheng = new PnlWznmVerDetail::DpchEngData();
			((PnlWznmVerDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERHEADBARDATA) {
			*dpcheng = new PnlWznmVerHeadbar::DpchEngData();
			((PnlWznmVerHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERLISTDATA) {
			*dpcheng = new PnlWznmVerList::DpchEngData();
			((PnlWznmVerList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERMNLOCALEDATA) {
			*dpcheng = new PnlWznmVerMNLocale::DpchEngData();
			((PnlWznmVerMNLocale::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERRECDATA) {
			*dpcheng = new PnlWznmVerRec::DpchEngData();
			((PnlWznmVerRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERREF1NFILEDATA) {
			*dpcheng = new PnlWznmVerRef1NFile::DpchEngData();
			((PnlWznmVerRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERVER1NAPPDATA) {
			*dpcheng = new PnlWznmVerVer1NApp::DpchEngData();
			((PnlWznmVerVer1NApp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERVER1NERRORDATA) {
			*dpcheng = new PnlWznmVerVer1NError::DpchEngData();
			((PnlWznmVerVer1NError::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERVER1NMODULEDATA) {
			*dpcheng = new PnlWznmVerVer1NModule::DpchEngData();
			((PnlWznmVerVer1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVERVER1NVISUALDATA) {
			*dpcheng = new PnlWznmVerVer1NVisual::DpchEngData();
			((PnlWznmVerVer1NVisual::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISDATA) {
			*dpcheng = new CrdWznmVis::DpchEngData();
			((CrdWznmVis::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISDETAILDATA) {
			*dpcheng = new PnlWznmVisDetail::DpchEngData();
			((PnlWznmVisDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISHEADBARDATA) {
			*dpcheng = new PnlWznmVisHeadbar::DpchEngData();
			((PnlWznmVisHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISLISTDATA) {
			*dpcheng = new PnlWznmVisList::DpchEngData();
			((PnlWznmVisList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISRECDATA) {
			*dpcheng = new PnlWznmVisRec::DpchEngData();
			((PnlWznmVisRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISREF1NFILEDATA) {
			*dpcheng = new PnlWznmVisRef1NFile::DpchEngData();
			((PnlWznmVisRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVISVIS1NSHEETDATA) {
			*dpcheng = new PnlWznmVisVis1NSheet::DpchEngData();
			((PnlWznmVisVis1NSheet::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVITDATA) {
			*dpcheng = new CrdWznmVit::DpchEngData();
			((CrdWznmVit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVITDETAILDATA) {
			*dpcheng = new PnlWznmVitDetail::DpchEngData();
			((PnlWznmVitDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVITHEADBARDATA) {
			*dpcheng = new PnlWznmVitHeadbar::DpchEngData();
			((PnlWznmVitHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVITLISTDATA) {
			*dpcheng = new PnlWznmVitList::DpchEngData();
			((PnlWznmVitList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHENGWZNMVITRECDATA) {
			*dpcheng = new PnlWznmVitRec::DpchEngData();
			((PnlWznmVitRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		};
	} catch (SbeException& e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWznmVDpch;
};

void ApiWznm::writeDpchApp(
			DpchAppWznm* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};
