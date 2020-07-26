/**
  * \file PnlWznmSteDetail.js
  * web client functionality for panel PnlWznmSteDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmSteDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSteDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmSteDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSteDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmSteDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmSteDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSeq", retrieveTi(srcdoc, "TagWznmSteDetail", "CptSeq"));
	initCpt(contcontdoc, "CptEac", retrieveTi(srcdoc, "TagWznmSteDetail", "CptEac"));
	refreshPup(contcontdoc, srcdoc, "PupEac", "", "FeedFPupEac", retrieveCi(srcdoc, "ContIacWznmSteDetail", "numFPupEac"), retrieveSi(srcdoc, "StatShrWznmSteDetail", "PupEacActive"), false);
	initCpt(contcontdoc, "CptErj", retrieveTi(srcdoc, "TagWznmSteDetail", "CptErj"));
	initCpt(contcontdoc, "CptEve", retrieveTi(srcdoc, "TagWznmSteDetail", "CptEve"));
	initCpt(contcontdoc, "CptEvi", retrieveTi(srcdoc, "TagWznmSteDetail", "CptEvi"));
	initCpt(contcontdoc, "CptEsn", retrieveTi(srcdoc, "TagWznmSteDetail", "CptEsn"));
	initCpt(contcontdoc, "CptLac", retrieveTi(srcdoc, "TagWznmSteDetail", "CptLac"));
	refreshPup(contcontdoc, srcdoc, "PupLac", "", "FeedFPupLac", retrieveCi(srcdoc, "ContIacWznmSteDetail", "numFPupLac"), retrieveSi(srcdoc, "StatShrWznmSteDetail", "PupLacActive"), false);
	initCpt(contcontdoc, "CptCst", retrieveTi(srcdoc, "TagWznmSteDetail", "CptCst"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmSteDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate");

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

	var height = 317; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtSrfActive") == "true");

	var TxtSeqActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtSeqActive") == "true");
	var ButSeqViewAvail = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButSeqViewAvail") == "true");
	var ButSeqViewActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButSeqViewActive") == "true");

	var PupEacActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "PupEacActive") == "true");

	var TxtErjActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtErjActive") == "true");
	var ButErjViewAvail = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButErjViewAvail") == "true");
	var ButErjViewActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButErjViewActive") == "true");

	var TxtEveActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtEveActive") == "true");
	var ButEveViewAvail = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEveViewAvail") == "true");
	var ButEveViewActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEveViewActive") == "true");

	var TxtEviActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtEviActive") == "true");
	var ButEviViewAvail = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEviViewAvail") == "true");
	var ButEviViewActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEviViewActive") == "true");

	var TxtEsnActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxtEsnActive") == "true");
	var ButEsnViewAvail = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEsnViewAvail") == "true");
	var ButEsnViewActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButEsnViewActive") == "true");

	var PupLacActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "PupLacActive") == "true");

	var ChkCstActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ChkCstActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmSteDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtSrf"));

	if ((ButSeqViewAvail == !contcontdoc.getElementById("ButSeqView"))) {
		mytd = contcontdoc.getElementById("rdynSeq");
		clearElem(mytd);

		first = true;

		if (ButSeqViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSeqView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSeq", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtSeq"));

	if (ButSeqViewAvail) refreshButicon(contcontdoc, "ButSeqView", "icon/view", ButSeqViewActive, false);

	contcontdoc.getElementById("PupEac").value = retrieveCi(srcdoc, "ContIacWznmSteDetail", "numFPupEac");

	if ((ButErjViewAvail == !contcontdoc.getElementById("ButErjView"))) {
		mytd = contcontdoc.getElementById("rdynErj");
		clearElem(mytd);

		first = true;

		if (ButErjViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButErjView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtErj", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtErj"));

	if (ButErjViewAvail) refreshButicon(contcontdoc, "ButErjView", "icon/view", ButErjViewActive, false);

	if ((ButEveViewAvail == !contcontdoc.getElementById("ButEveView"))) {
		mytd = contcontdoc.getElementById("rdynEve");
		clearElem(mytd);

		first = true;

		if (ButEveViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEveView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtEve", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtEve"));

	if (ButEveViewAvail) refreshButicon(contcontdoc, "ButEveView", "icon/view", ButEveViewActive, false);

	if ((ButEviViewAvail == !contcontdoc.getElementById("ButEviView"))) {
		mytd = contcontdoc.getElementById("rdynEvi");
		clearElem(mytd);

		first = true;

		if (ButEviViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEviView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtEvi", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtEvi"));

	if (ButEviViewAvail) refreshButicon(contcontdoc, "ButEviView", "icon/view", ButEviViewActive, false);

	if ((ButEsnViewAvail == !contcontdoc.getElementById("ButEsnView"))) {
		mytd = contcontdoc.getElementById("rdynEsn");
		clearElem(mytd);

		first = true;

		if (ButEsnViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEsnView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtEsn", retrieveCi(srcdoc, "ContInfWznmSteDetail", "TxtEsn"));

	if (ButEsnViewAvail) refreshButicon(contcontdoc, "ButEsnView", "icon/view", ButEsnViewActive, false);

	contcontdoc.getElementById("PupLac").value = retrieveCi(srcdoc, "ContIacWznmSteDetail", "numFPupLac");

	refreshChk(contcontdoc, "ChkCst", (retrieveCi(srcdoc, "ContIacWznmSteDetail", "ChkCst") == "true"), ChkCstActive);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmSteDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSteDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSteDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSteDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmSteDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSteDetailData", scrJref, "ContIacWznmSteDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmSteDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSteDetailData", scrJref, "ContIacWznmSteDetail");
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

	setCi(srcdoc, "ContIacWznmSteDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSteDetailData", scrJref, "ContIacWznmSteDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "ContIacWznmSteDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "ContInfWznmSteDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "FeedFPupEac", srcdoc)) mask.push("feedFPupEac");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "FeedFPupLac", srcdoc)) mask.push("feedFPupLac");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "StatAppWznmSteDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "StatShrWznmSteDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmSteDetailData", "TagWznmSteDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmSteDetailData") {
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
			if (blk.nodeName == "DpchEngWznmSteDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmSteDetailData") {
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

