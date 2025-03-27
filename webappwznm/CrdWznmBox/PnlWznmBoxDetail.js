// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmBoxDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmBoxDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmBoxDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmBoxDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmBoxDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSht", retrieveTi(srcdoc, "TagWznmBoxDetail", "CptSht"));
	initCpt(contcontdoc, "CptUnv", retrieveTi(srcdoc, "TagWznmBoxDetail", "CptUnv"));
	initCpt(contcontdoc, "CptX", retrieveTi(srcdoc, "TagWznmBoxDetail", "CptX"));
	initCpt(contcontdoc, "CptY", retrieveTi(srcdoc, "TagWznmBoxDetail", "CptY"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate");

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

	var height = 110; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtShtActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "TxtShtActive") == "true");
	var ButShtViewAvail = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "ButShtViewAvail") == "true");
	var ButShtViewActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "ButShtViewActive") == "true");

	var TxtUnvActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "TxtUnvActive") == "true");

	var TxfXActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "TxfXActive") == "true");

	var TxfYActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "TxfYActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmBoxDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButShtViewAvail == !contcontdoc.getElementById("ButShtView"))) {
		mytd = contcontdoc.getElementById("rdynSht");
		clearElem(mytd);

		first = true;

		if (ButShtViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButShtView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSht", retrieveCi(srcdoc, "ContInfWznmBoxDetail", "TxtSht"));

	if (ButShtViewAvail) refreshButicon(contcontdoc, "ButShtView", "icon/view", ButShtViewActive, false);

	refreshTxt(contcontdoc, "TxtUnv", retrieveCi(srcdoc, "ContInfWznmBoxDetail", "TxtUnv"));
	refreshPup(contcontdoc, srcdoc, "PupY", "xs", "FeedFPupY", retrieveCi(srcdoc, "ContIacWznmBoxDetail", "numFPupY"), TxtUnvActive, false);

	refreshTxf(contcontdoc, "TxfX", "s", retrieveCi(srcdoc, "ContIacWznmBoxDetail", "TxfX"), TxfXActive, false, true);

	refreshTxf(contcontdoc, "TxfY", "s", retrieveCi(srcdoc, "ContIacWznmBoxDetail", "TxfY"), TxfYActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmBoxDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmBoxDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmBoxDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmBoxDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmBoxDetailData", scrJref, "ContIacWznmBoxDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmBoxDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmBoxDetailData", scrJref, "ContIacWznmBoxDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmBoxDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmBoxDetailData", scrJref, "ContIacWznmBoxDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "ContIacWznmBoxDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "ContInfWznmBoxDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "FeedFPupY", srcdoc)) mask.push("feedFPupY");
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "StatAppWznmBoxDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "StatShrWznmBoxDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmBoxDetailData", "TagWznmBoxDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmBoxDetailData") {
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
			if (blk.nodeName == "DpchEngWznmBoxDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmBoxDetailData") {
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
