// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmCarDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmCarDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmCarDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmCarDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmCarDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmCarDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmCarDetail", "CptTit"));
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWznmCarDetail", "CptMdl"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmCarDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmCarDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWznmCarDetail", "CptJob"));
	initCpt(contcontdoc, "CptAvl", retrieveTi(srcdoc, "TagWznmCarDetail", "CptAvl"));
	initCpt(contcontdoc, "CptAct", retrieveTi(srcdoc, "TagWznmCarDetail", "CptAct"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxtSrfActive") == "true");

	var PupJtiActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "PupJtiActive") == "true");
	var ButJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButJtiEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxtTitActive") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButMdlViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButReuViewActive") == "true");

	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButJobViewActive") == "true");

	var TxfAvlActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxfAvlActive") == "true");

	var TxfActActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "TxfActActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmCarDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmCarDetail", "TxtSrf"));

	if ((ButJtiEditAvail == !contcontdoc.getElementById("ButJtiEdit"))) {
		mytd = contcontdoc.getElementById("rdynJti");
		clearElem(mytd);

		first = true;

		if (ButJtiEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJtiEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJti", "s", "FeedFPupJti", retrieveCi(srcdoc, "ContIacWznmCarDetail", "numFPupJti"), PupJtiActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmCarDetail", "TxtTit"));

	if ((ButMdlViewAvail == !contcontdoc.getElementById("ButMdlView"))) {
		mytd = contcontdoc.getElementById("rdynMdl");
		clearElem(mytd);

		first = true;

		if (ButMdlViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMdlView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWznmCarDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmCarDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmCarDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

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

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWznmCarDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshTxft(contcontdoc, "TxfAvl", retrieveCi(srcdoc, "ContIacWznmCarDetail", "TxfAvl"), TxfAvlActive, false, true);

	refreshTxft(contcontdoc, "TxfAct", retrieveCi(srcdoc, "ContIacWznmCarDetail", "TxfAct"), TxfActActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmCarDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCarDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCarDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCarDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmCarDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmCarDetailData", scrJref, "ContIacWznmCarDetail");
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

	setCi(srcdoc, "ContIacWznmCarDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmCarDetailData", scrJref, "ContIacWznmCarDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "ContIacWznmCarDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "ContInfWznmCarDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "FeedFPupJti", srcdoc)) mask.push("feedFPupJti");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "StatAppWznmCarDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "StatShrWznmCarDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmCarDetailData", "TagWznmCarDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmCarDetailData") {
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
			if (blk.nodeName == "DpchEngWznmCarDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmCarDetailData") {
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

