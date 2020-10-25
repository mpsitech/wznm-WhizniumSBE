/**
  * \file PnlWznmMtdDetail.js
  * web client functionality for panel PnlWznmMtdDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmMtdDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMtdDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmMtdDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMtdDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmMtdDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmMtdDetail", "CptSrf"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmMtdDetail", "CptCmt"));
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWznmMtdDetail", "CptJob"));
	initCpt(contcontdoc, "CptExs", retrieveTi(srcdoc, "TagWznmMtdDetail", "CptExs"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		initA();
	} else if (srefIxWznmVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 167; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "TxtSrfActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "TxfCmtActive") == "true");

	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "ButJobViewActive") == "true");

	var ChkExsActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "ChkExsActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmMtdDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmMtdDetail", "TxtSrf"));

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmMtdDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButJobViewAvail == !contcontdoc.getElementById("ButJobView"))) {
		mytd = contcontdoc.getElementById("rdynJob");
		clearElem(mytd);

		first = true;

		if (ButJobViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJobView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWznmMtdDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshChk(contcontdoc, "ChkExs", (retrieveCi(srcdoc, "ContIacWznmMtdDetail", "ChkExs") == "true"), ChkExsActive);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMtdDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		refreshA();
	} else if (srefIxWznmVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMtdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMtdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmMtdDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtdDetailData", scrJref, "ContIacWznmMtdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWznmMtdDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtdDetailData", scrJref, "ContIacWznmMtdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmMtdDetailData", "ContIacWznmMtdDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmMtdDetailData", "ContInfWznmMtdDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmMtdDetailData", "StatAppWznmMtdDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmMtdDetailData", "StatShrWznmMtdDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmMtdDetailData", "TagWznmMtdDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmMtdDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWznmMtdDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWznmMtdDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");
				_scrJref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:scrJref");
				sref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWznmAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));
			};
		};
	};
};

