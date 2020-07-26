/**
  * \file PnlWznmSgeDetail.js
  * web client functionality for panel PnlWznmSgeDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmSgeDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSgeDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmSgeDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSgeDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmSgeDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmSgeDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmSgeDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptJob"));
	initCpt(contcontdoc, "CptMon", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptMon"));
	initCpt(contcontdoc, "CptSnx", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptSnx"));
	initCpt(contcontdoc, "CptFnx", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptFnx"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptCmt"));
	initCpt(contcontdoc, "CptSqkTit", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptSqkTit"));
	initCpt(contcontdoc, "CptSqkExa", retrieveTi(srcdoc, "TagWznmSgeDetail", "CptSqkExa"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate");

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

	var height = 349; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtSrfActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "PupTypActive") == "true");

	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButJobViewActive") == "true");

	var TxfMonActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxfMonActive") == "true");

	var TxtSnxActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtSnxActive") == "true");
	var ButSnxViewAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSnxViewAvail") == "true");
	var ButSnxViewActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSnxViewActive") == "true");

	var TxtFnxActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtFnxActive") == "true");
	var ButFnxViewAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButFnxViewAvail") == "true");
	var ButFnxViewActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButFnxViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxfCmtActive") == "true");

	var ButSqkNewAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSqkNewAvail") == "true");
	var ButSqkDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSqkDeleteAvail") == "true");

	var PupSqkJtiAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "PupSqkJtiAvail") == "true");
	var PupSqkJtiActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "PupSqkJtiActive") == "true");
	var ButSqkJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSqkJtiEditAvail") == "true");

	var TxtSqkTitAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtSqkTitAvail") == "true");
	var TxtSqkTitActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxtSqkTitActive") == "true");

	var TxfSqkExaAvail = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxfSqkExaAvail") == "true");
	var TxfSqkExaActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "TxfSqkExaActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmSgeDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmSgeDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmSgeDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWznmSgeDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshTxf(contcontdoc, "TxfMon", "s", retrieveCi(srcdoc, "ContIacWznmSgeDetail", "TxfMon"), TxfMonActive, false, true);

	if ((ButSnxViewAvail == !contcontdoc.getElementById("ButSnxView"))) {
		mytd = contcontdoc.getElementById("rdynSnx");
		clearElem(mytd);

		first = true;

		if (ButSnxViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSnxView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSnx", retrieveCi(srcdoc, "ContInfWznmSgeDetail", "TxtSnx"));

	if (ButSnxViewAvail) refreshButicon(contcontdoc, "ButSnxView", "icon/view", ButSnxViewActive, false);

	if ((ButFnxViewAvail == !contcontdoc.getElementById("ButFnxView"))) {
		mytd = contcontdoc.getElementById("rdynFnx");
		clearElem(mytd);

		first = true;

		if (ButFnxViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFnxView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtFnx", retrieveCi(srcdoc, "ContInfWznmSgeDetail", "TxtFnx"));

	if (ButFnxViewAvail) refreshButicon(contcontdoc, "ButFnxView", "icon/view", ButFnxViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmSgeDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButSqkNewAvail == !contcontdoc.getElementById("ButSqkNew")) || (ButSqkDeleteAvail == !contcontdoc.getElementById("ButSqkDelete"))) {
		mytd = contcontdoc.getElementById("dynSqk");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgSqk", retrieveTi(srcdoc, "TagWznmSgeDetail", "HdgSqk")));
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

		refreshPup(contcontdoc, srcdoc, "PupSqkJti", "s", "FeedFPupSqkJti", retrieveCi(srcdoc, "ContIacWznmSgeDetail", "numFPupSqkJti"), PupSqkJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "SqkTit", TxtSqkTitAvail, 25);
	if (TxtSqkTitAvail) {
		refreshTxt(contcontdoc, "TxtSqkTit", retrieveCi(srcdoc, "ContInfWznmSgeDetail", "TxtSqkTit"));

	};

	height -= setCtlAvail(contcontdoc, "SqkExa", TxfSqkExaAvail, 25);
	if (TxfSqkExaAvail) {
		refreshTxf(contcontdoc, "TxfSqkExa", "", retrieveCi(srcdoc, "ContIacWznmSgeDetail", "TxfSqkExa"), TxfSqkExaActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSgeDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSgeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSgeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSgeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmSgeDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSgeDetailData", scrJref, "ContIacWznmSgeDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmSgeDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmSgeDetailData", scrJref, "ContIacWznmSgeDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmSgeDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSgeDetailData", scrJref, "ContIacWznmSgeDetail");
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

	setCi(srcdoc, "ContIacWznmSgeDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSgeDetailData", scrJref, "ContIacWznmSgeDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "ContIacWznmSgeDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "ContInfWznmSgeDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "FeedFPupSqkJti", srcdoc)) mask.push("feedFPupSqkJti");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "StatAppWznmSgeDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "StatShrWznmSgeDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmSgeDetailData", "TagWznmSgeDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmSgeDetailData") {
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
			if (blk.nodeName == "DpchEngWznmSgeDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmSgeDetailData") {
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

