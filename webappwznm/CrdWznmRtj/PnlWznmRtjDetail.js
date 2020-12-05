// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmRtjDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmRtjDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmRtjDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmRtjDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmRtjDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmRtjDetail", "CptSrf"));
	initCpt(contcontdoc, "CptApp", retrieveTi(srcdoc, "TagWznmRtjDetail", "CptApp"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWznmRtjDetail", "CptSup"));
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWznmRtjDetail", "CptJob"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmRtjDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "TxtSrfActive") == "true");

	var TxtAppActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "TxtAppActive") == "true");
	var ButAppViewAvail = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButAppViewAvail") == "true");
	var ButAppViewActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButAppViewActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButSupViewActive") == "true");

	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButJobViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmRtjDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmRtjDetail", "TxtSrf"));

	if ((ButAppViewAvail == !contcontdoc.getElementById("ButAppView"))) {
		mytd = contcontdoc.getElementById("rdynApp");
		clearElem(mytd);

		first = true;

		if (ButAppViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAppView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtApp", retrieveCi(srcdoc, "ContInfWznmRtjDetail", "TxtApp"));

	if (ButAppViewAvail) refreshButicon(contcontdoc, "ButAppView", "icon/view", ButAppViewActive, false);

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

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWznmRtjDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

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

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWznmRtjDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmRtjDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmRtjDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmRtjDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmRtjDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWznmRtjDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmRtjDetailData", scrJref, "ContIacWznmRtjDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmRtjDetailData", "ContIacWznmRtjDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmRtjDetailData", "ContInfWznmRtjDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmRtjDetailData", "StatAppWznmRtjDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmRtjDetailData", "StatShrWznmRtjDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmRtjDetailData", "TagWznmRtjDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmRtjDetailData") {
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
			if (blk.nodeName == "DpchEngWznmRtjDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmRtjDetailData") {
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

