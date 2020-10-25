/**
  * \file PnlWznmMtyDetail.js
  * web client functionality for panel PnlWznmMtyDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmMtyDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMtyDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmMtyDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMtyDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmMtyDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptSrf"));
	initCpt(contcontdoc, "CptAch", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptAch"));
	refreshPup(contcontdoc, srcdoc, "PupAch", "", "FeedFPupAch", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "numFPupAch"), retrieveSi(srcdoc, "StatShrWznmMtyDetail", "PupAchActive"), false);
	initCpt(contcontdoc, "CptOs", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptOs"));
	initCpt(contcontdoc, "CptCch", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptCch"));
	initCpt(contcontdoc, "CptPkm", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptPkm"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmMtyDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate");

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

	var height = 217; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "TxtSrfActive") == "true");

	var PupAchActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "PupAchActive") == "true");

	var PupOsAlt = (retrieveSi(srcdoc, "StatAppWznmMtyDetail", "PupOsAlt") == "true");
	var TxfOsValid = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "TxfOsValid") == "true");
	var PupOsActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "PupOsActive") == "true");
	var ButOsEditAvail = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "ButOsEditAvail") == "true");

	var TxtCchActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "TxtCchActive") == "true");
	var ButCchViewAvail = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "ButCchViewAvail") == "true");
	var ButCchViewActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "ButCchViewActive") == "true");

	var PupPkmAlt = (retrieveSi(srcdoc, "StatAppWznmMtyDetail", "PupPkmAlt") == "true");
	var TxfPkmValid = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "TxfPkmValid") == "true");
	var PupPkmActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "PupPkmActive") == "true");
	var ButPkmEditAvail = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "ButPkmEditAvail") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmMtyDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmMtyDetail", "TxtSrf"));

	contcontdoc.getElementById("PupAch").value = retrieveCi(srcdoc, "ContIacWznmMtyDetail", "numFPupAch");

	if ( (PupOsAlt == !contcontdoc.getElementById("TxfOs")) || (!PupOsAlt == !contcontdoc.getElementById("PupOs")) ) {
		mytd = contcontdoc.getElementById("dynOs");
		clearElem(mytd);

		if (PupOsAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfOs", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupOs", ""));
	};

	if (PupOsAlt) refreshTxf(contcontdoc, "TxfOs", "", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "TxfOs"), PupOsActive, false, TxfOsValid);
	else refreshPup(contcontdoc, srcdoc, "PupOs", "", "FeedFPupOs", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "numFPupOs"), true, false);

	if ((ButOsEditAvail == !contcontdoc.getElementById("ButOsEdit"))) {
		mytd = contcontdoc.getElementById("rdynOs");
		clearElem(mytd);

		first = true;

		if (ButOsEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOsEdit", "icon/edit"));
		};
	};

	if ((ButCchViewAvail == !contcontdoc.getElementById("ButCchView"))) {
		mytd = contcontdoc.getElementById("rdynCch");
		clearElem(mytd);

		first = true;

		if (ButCchViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCchView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCch", retrieveCi(srcdoc, "ContInfWznmMtyDetail", "TxtCch"));

	if (ButCchViewAvail) refreshButicon(contcontdoc, "ButCchView", "icon/view", ButCchViewActive, false);

	if ( (PupPkmAlt == !contcontdoc.getElementById("TxfPkm")) || (!PupPkmAlt == !contcontdoc.getElementById("PupPkm")) ) {
		mytd = contcontdoc.getElementById("dynPkm");
		clearElem(mytd);

		if (PupPkmAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPkm", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupPkm", ""));
	};

	if (PupPkmAlt) refreshTxf(contcontdoc, "TxfPkm", "", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "TxfPkm"), PupPkmActive, false, TxfPkmValid);
	else refreshPup(contcontdoc, srcdoc, "PupPkm", "", "FeedFPupPkm", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "numFPupPkm"), true, false);

	if ((ButPkmEditAvail == !contcontdoc.getElementById("ButPkmEdit"))) {
		mytd = contcontdoc.getElementById("rdynPkm");
		clearElem(mytd);

		first = true;

		if (ButPkmEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPkmEdit", "icon/edit"));
		};
	};

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmMtyDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMtyDetail", "srefIxWznmVExpstate");

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

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWznmMtyDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWznmMtyDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMtyDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMtyDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMtyDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmMtyDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtyDetailData", scrJref, "ContIacWznmMtyDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmMtyDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtyDetailData", scrJref, "ContIacWznmMtyDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmMtyDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtyDetailData", scrJref, "ContIacWznmMtyDetail");
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

	setCi(srcdoc, "ContIacWznmMtyDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMtyDetailData", scrJref, "ContIacWznmMtyDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "ContIacWznmMtyDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "ContInfWznmMtyDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "FeedFPupAch", srcdoc)) mask.push("feedFPupAch");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "FeedFPupOs", srcdoc)) mask.push("feedFPupOs");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "FeedFPupPkm", srcdoc)) mask.push("feedFPupPkm");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "StatAppWznmMtyDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "StatShrWznmMtyDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmMtyDetailData", "TagWznmMtyDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmMtyDetailData") {
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
			if (blk.nodeName == "DpchEngWznmMtyDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmMtyDetailData") {
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

function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

