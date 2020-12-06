// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmCmpDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmCmpDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmCmpDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmCmpDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmCmpDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmCmpDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmCmpDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmCmpDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmCmpDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmCmpDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmCmpDetail", "CptVer"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmCmpDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "TxtSrfActive") == "true");

	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "TxfTitActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "PupTypActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "ButVerViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmCmpDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmCmpDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacWznmCmpDetail", "TxfTit"), TxfTitActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmCmpDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmCmpDetail", "TxtVer"));

	if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmCmpDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmCmpDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCmpDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCmpDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmCmpDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmCmpDetailData", scrJref, "ContIacWznmCmpDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmCmpDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmCmpDetailData", scrJref, "ContIacWznmCmpDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmCmpDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmCmpDetailData", scrJref, "ContIacWznmCmpDetail");
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

	setCi(srcdoc, "ContIacWznmCmpDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmCmpDetailData", scrJref, "ContIacWznmCmpDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "ContIacWznmCmpDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "ContInfWznmCmpDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "StatAppWznmCmpDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "StatShrWznmCmpDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmCmpDetailData", "TagWznmCmpDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmCmpDetailData") {
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
			if (blk.nodeName == "DpchEngWznmCmpDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmCmpDetailData") {
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
