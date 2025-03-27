// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmMchDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMchDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmMchDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmMchDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmMchDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmMchDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWznmMchDetail", "CptSup"));
	initCpt(contcontdoc, "CptCch", retrieveTi(srcdoc, "TagWznmMchDetail", "CptCch"));
	initCpt(contcontdoc, "CptPkm", retrieveTi(srcdoc, "TagWznmMchDetail", "CptPkm"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmMchDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate");

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

	var height = 192; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "TxtSrfActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButSupViewActive") == "true");

	var TxtCchActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "TxtCchActive") == "true");
	var ButCchViewAvail = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButCchViewAvail") == "true");
	var ButCchViewActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButCchViewActive") == "true");

	var PupPkmAlt = (retrieveSi(srcdoc, "StatAppWznmMchDetail", "PupPkmAlt") == "true");
	var TxfPkmValid = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "TxfPkmValid") == "true");
	var PupPkmActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "PupPkmActive") == "true");
	var ButPkmEditAvail = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButPkmEditAvail") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmMchDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmMchDetail", "TxtSrf"));

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWznmMchDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

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

	refreshTxt(contcontdoc, "TxtCch", retrieveCi(srcdoc, "ContInfWznmMchDetail", "TxtCch"));

	if (ButCchViewAvail) refreshButicon(contcontdoc, "ButCchView", "icon/view", ButCchViewActive, false);

	if ( (PupPkmAlt == !contcontdoc.getElementById("TxfPkm")) || (!PupPkmAlt == !contcontdoc.getElementById("PupPkm")) ) {
		mytd = contcontdoc.getElementById("dynPkm");
		clearElem(mytd);

		if (PupPkmAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPkm", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupPkm", ""));
	};

	if (PupPkmAlt) refreshTxf(contcontdoc, "TxfPkm", "", retrieveCi(srcdoc, "ContIacWznmMchDetail", "TxfPkm"), PupPkmActive, false, TxfPkmValid);
	else refreshPup(contcontdoc, srcdoc, "PupPkm", "", "FeedFPupPkm", retrieveCi(srcdoc, "ContIacWznmMchDetail", "numFPupPkm"), true, false);

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

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmMchDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmMchDetail", "srefIxWznmVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWznmMchDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWznmMchDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMchDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMchDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmMchDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmMchDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMchDetailData", scrJref, "ContIacWznmMchDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmMchDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmMchDetailData", scrJref, "ContIacWznmMchDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmMchDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMchDetailData", scrJref, "ContIacWznmMchDetail");
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

	setCi(srcdoc, "ContIacWznmMchDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmMchDetailData", scrJref, "ContIacWznmMchDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "ContIacWznmMchDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "ContInfWznmMchDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "FeedFPupPkm", srcdoc)) mask.push("feedFPupPkm");
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "StatAppWznmMchDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "StatShrWznmMchDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmMchDetailData", "TagWznmMchDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmMchDetailData") {
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
			if (blk.nodeName == "DpchEngWznmMchDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmMchDetailData") {
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
