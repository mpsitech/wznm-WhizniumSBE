// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmOpkDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmOpkDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmOpkDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmOpkDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmOpkDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmOpkDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmOpkDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptVer"));
	initCpt(contcontdoc, "CptShd", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptShd"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptCmt"));
	initCpt(contcontdoc, "CptSqkTit", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptSqkTit"));
	initCpt(contcontdoc, "CptSqkExa", retrieveTi(srcdoc, "TagWznmOpkDetail", "CptSqkExa"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate");

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

	var height = 324; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxtSrfActive") == "true");

	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxfTitActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "PupTypActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButVerViewActive") == "true");

	var ChkShdActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ChkShdActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxfCmtActive") == "true");

	var ButSqkNewAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButSqkNewAvail") == "true");
	var ButSqkDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButSqkDeleteAvail") == "true");

	var PupSqkJtiAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "PupSqkJtiAvail") == "true");
	var PupSqkJtiActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "PupSqkJtiActive") == "true");
	var ButSqkJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButSqkJtiEditAvail") == "true");

	var TxtSqkTitAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxtSqkTitAvail") == "true");
	var TxtSqkTitActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxtSqkTitActive") == "true");

	var TxfSqkExaAvail = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxfSqkExaAvail") == "true");
	var TxfSqkExaActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "TxfSqkExaActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmOpkDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmOpkDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacWznmOpkDetail", "TxfTit"), TxfTitActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmOpkDetail", "numFPupTyp");

	if ((ButVerViewAvail == !contcontdoc.getElementById("ButVerView"))) {
		mytd = contcontdoc.getElementById("rdynVer");
		clearElem(mytd);

		first = true;

		if (ButVerViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVerView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmOpkDetail", "TxtVer"));

	if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	refreshChk(contcontdoc, "ChkShd", (retrieveCi(srcdoc, "ContIacWznmOpkDetail", "ChkShd") == "true"), ChkShdActive);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmOpkDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButSqkNewAvail == !contcontdoc.getElementById("ButSqkNew")) || (ButSqkDeleteAvail == !contcontdoc.getElementById("ButSqkDelete"))) {
		mytd = contcontdoc.getElementById("dynSqk");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgSqk", retrieveTi(srcdoc, "TagWznmOpkDetail", "HdgSqk")));
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

		refreshPup(contcontdoc, srcdoc, "PupSqkJti", "s", "FeedFPupSqkJti", retrieveCi(srcdoc, "ContIacWznmOpkDetail", "numFPupSqkJti"), PupSqkJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "SqkTit", TxtSqkTitAvail, 25);
	if (TxtSqkTitAvail) {
		refreshTxt(contcontdoc, "TxtSqkTit", retrieveCi(srcdoc, "ContInfWznmOpkDetail", "TxtSqkTit"));

	};

	height -= setCtlAvail(contcontdoc, "SqkExa", TxfSqkExaAvail, 25);
	if (TxfSqkExaAvail) {
		refreshTxf(contcontdoc, "TxfSqkExa", "", retrieveCi(srcdoc, "ContIacWznmOpkDetail", "TxfSqkExa"), TxfSqkExaActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmOpkDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmOpkDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpkDetailData", scrJref, "ContIacWznmOpkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmOpkDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpkDetailData", scrJref, "ContIacWznmOpkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmOpkDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpkDetailData", scrJref, "ContIacWznmOpkDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmOpkDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpkDetailData", scrJref, "ContIacWznmOpkDetail");
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

	setCi(srcdoc, "ContIacWznmOpkDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmOpkDetailData", scrJref, "ContIacWznmOpkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "ContIacWznmOpkDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "ContInfWznmOpkDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "FeedFPupSqkJti", srcdoc)) mask.push("feedFPupSqkJti");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "StatAppWznmOpkDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "StatShrWznmOpkDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmOpkDetailData", "TagWznmOpkDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmOpkDetailData") {
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
			if (blk.nodeName == "DpchEngWznmOpkDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmOpkDetailData") {
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

