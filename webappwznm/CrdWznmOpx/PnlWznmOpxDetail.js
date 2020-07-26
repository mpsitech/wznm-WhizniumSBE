/**
  * \file PnlWznmOpxDetail.js
  * web client functionality for panel PnlWznmOpxDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmOpxDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmOpxDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmOpxDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmOpxDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmOpxDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptSrf"));
	initCpt(contcontdoc, "CptOpk", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptOpk"));
	initCpt(contcontdoc, "CptShd", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptShd"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptCmt"));
	initCpt(contcontdoc, "CptSqkTit", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptSqkTit"));
	initCpt(contcontdoc, "CptSqkExa", retrieveTi(srcdoc, "TagWznmOpxDetail", "CptSqkExa"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate");

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

	var height = 274; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxtSrfActive") == "true");

	var TxtOpkActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxtOpkActive") == "true");
	var ButOpkViewAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButOpkViewAvail") == "true");
	var ButOpkViewActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButOpkViewActive") == "true");

	var ChkShdActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ChkShdActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxfCmtActive") == "true");

	var ButSqkNewAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButSqkNewAvail") == "true");
	var ButSqkDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButSqkDeleteAvail") == "true");

	var PupSqkJtiAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "PupSqkJtiAvail") == "true");
	var PupSqkJtiActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "PupSqkJtiActive") == "true");
	var ButSqkJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButSqkJtiEditAvail") == "true");

	var TxtSqkTitAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxtSqkTitAvail") == "true");
	var TxtSqkTitActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxtSqkTitActive") == "true");

	var TxfSqkExaAvail = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxfSqkExaAvail") == "true");
	var TxfSqkExaActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "TxfSqkExaActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmOpxDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmOpxDetail", "TxtSrf"));

	if ((ButOpkViewAvail == !contcontdoc.getElementById("ButOpkView"))) {
		mytd = contcontdoc.getElementById("rdynOpk");
		clearElem(mytd);

		first = true;

		if (ButOpkViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOpkView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtOpk", retrieveCi(srcdoc, "ContInfWznmOpxDetail", "TxtOpk"));

	if (ButOpkViewAvail) refreshButicon(contcontdoc, "ButOpkView", "icon/view", ButOpkViewActive, false);

	refreshChk(contcontdoc, "ChkShd", (retrieveCi(srcdoc, "ContIacWznmOpxDetail", "ChkShd") == "true"), ChkShdActive);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmOpxDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButSqkNewAvail == !contcontdoc.getElementById("ButSqkNew")) || (ButSqkDeleteAvail == !contcontdoc.getElementById("ButSqkDelete"))) {
		mytd = contcontdoc.getElementById("dynSqk");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgSqk", retrieveTi(srcdoc, "TagWznmOpxDetail", "HdgSqk")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButSqkNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSqkNew", "icon/new"));
		};

		if (ButSqkDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSqkDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "SqkJti", PupSqkJtiAvail, 25);
	if (PupSqkJtiAvail) {
		if ((ButSqkJtiEditAvail == !contcontdoc.getElementById("ButSqkJtiEdit"))) {
			mytd = contcontdoc.getElementById("rdynSqkJti");
			clearElem(mytd);

			first = true;

			if (ButSqkJtiEditAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSqkJtiEdit", "icon/edit"));
			};
		};

		refreshPup(contcontdoc, srcdoc, "PupSqkJti", "s", "FeedFPupSqkJti", retrieveCi(srcdoc, "ContIacWznmOpxDetail", "numFPupSqkJti"), PupSqkJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "SqkTit", TxtSqkTitAvail, 25);
	if (TxtSqkTitAvail) {
		refreshTxt(contcontdoc, "TxtSqkTit", retrieveCi(srcdoc, "ContInfWznmOpxDetail", "TxtSqkTit"));

	};

	height -= setCtlAvail(contcontdoc, "SqkExa", TxfSqkExaAvail, 25);
	if (TxfSqkExaAvail) {
		refreshTxf(contcontdoc, "TxfSqkExa", "", retrieveCi(srcdoc, "ContIacWznmOpxDetail", "TxfSqkExa"), TxfSqkExaActive, false, true);

	};

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmOpxDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpxDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpxDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpxDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmOpxDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpxDetailData", scrJref, "ContIacWznmOpxDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmOpxDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpxDetailData", scrJref, "ContIacWznmOpxDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmOpxDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpxDetailData", scrJref, "ContIacWznmOpxDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmOpxDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpxDetailData", scrJref, "ContIacWznmOpxDetail");
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

	setCi(srcdoc, "ContIacWznmOpxDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpxDetailData", scrJref, "ContIacWznmOpxDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "ContIacWznmOpxDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "ContInfWznmOpxDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "FeedFPupSqkJti", srcdoc)) mask.push("feedFPupSqkJti");
	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "StatAppWznmOpxDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "StatShrWznmOpxDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmOpxDetailData", "TagWznmOpxDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmOpxDetailData") {
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
			if (blk.nodeName == "DpchEngWznmOpxDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmOpxDetailData") {
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

