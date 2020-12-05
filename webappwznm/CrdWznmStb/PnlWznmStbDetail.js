// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmStbDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmStbDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmStbDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmStbDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmStbDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmStbDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmStbDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmStbDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmStbDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptTbl", retrieveTi(srcdoc, "TagWznmStbDetail", "CptTbl"));
	initCpt(contcontdoc, "CptSbs", retrieveTi(srcdoc, "TagWznmStbDetail", "CptSbs"));
	initCpt(contcontdoc, "CptHrc", retrieveTi(srcdoc, "TagWznmStbDetail", "CptHrc"));
	initCpt(contcontdoc, "CptTco", retrieveTi(srcdoc, "TagWznmStbDetail", "CptTco"));
	initCpt(contcontdoc, "CptLcl", retrieveTi(srcdoc, "TagWznmStbDetail", "CptLcl"));
	initCpt(contcontdoc, "CptExa", retrieveTi(srcdoc, "TagWznmStbDetail", "CptExa"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "TxtSrfActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "PupTypActive") == "true");

	var TxtTblActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "TxtTblActive") == "true");

	var TxtSbsActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "TxtSbsActive") == "true");
	var ButSbsViewAvail = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ButSbsViewAvail") == "true");
	var ButSbsViewActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ButSbsViewActive") == "true");

	var ChkHrcActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ChkHrcActive") == "true");

	var TxtTcoActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "TxtTcoActive") == "true");
	var ButTcoViewAvail = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ButTcoViewAvail") == "true");
	var ButTcoViewActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ButTcoViewActive") == "true");

	var ChkLclActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ChkLclActive") == "true");

	var TxfExaActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "TxfExaActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmStbDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmStbDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmStbDetail", "numFPupTyp");

	refreshTxt(contcontdoc, "TxtTbl", retrieveCi(srcdoc, "ContInfWznmStbDetail", "TxtTbl"));

	if ((ButSbsViewAvail == !contcontdoc.getElementById("ButSbsView"))) {
		mytd = contcontdoc.getElementById("rdynSbs");
		clearElem(mytd);

		first = true;

		if (ButSbsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSbsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSbs", retrieveCi(srcdoc, "ContInfWznmStbDetail", "TxtSbs"));

	if (ButSbsViewAvail) refreshButicon(contcontdoc, "ButSbsView", "icon/view", ButSbsViewActive, false);

	refreshChk(contcontdoc, "ChkHrc", (retrieveCi(srcdoc, "ContIacWznmStbDetail", "ChkHrc") == "true"), ChkHrcActive);

	if ((ButTcoViewAvail == !contcontdoc.getElementById("ButTcoView"))) {
		mytd = contcontdoc.getElementById("rdynTco");
		clearElem(mytd);

		first = true;

		if (ButTcoViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTcoView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTco", retrieveCi(srcdoc, "ContInfWznmStbDetail", "TxtTco"));

	if (ButTcoViewAvail) refreshButicon(contcontdoc, "ButTcoView", "icon/view", ButTcoViewActive, false);

	refreshChk(contcontdoc, "ChkLcl", (retrieveCi(srcdoc, "ContIacWznmStbDetail", "ChkLcl") == "true"), ChkLclActive);

	refreshTxf(contcontdoc, "TxfExa", "", retrieveCi(srcdoc, "ContIacWznmStbDetail", "TxfExa"), TxfExaActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmStbDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmStbDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmStbDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmStbDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmStbDetailData", scrJref, "ContIacWznmStbDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmStbDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmStbDetailData", scrJref, "ContIacWznmStbDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmStbDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmStbDetailData", scrJref, "ContIacWznmStbDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmStbDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmStbDetailData", scrJref, "ContIacWznmStbDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "ContIacWznmStbDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "ContInfWznmStbDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "StatAppWznmStbDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "StatShrWznmStbDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmStbDetailData", "TagWznmStbDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmStbDetailData") {
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
			if (blk.nodeName == "DpchEngWznmStbDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmStbDetailData") {
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

