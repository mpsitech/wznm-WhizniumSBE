// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmVitDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVitDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmVitDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVitDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmVitDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmVitDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmVitDetail", "CptTit"));
	initCpt(contcontdoc, "CptVec", retrieveTi(srcdoc, "TagWznmVitDetail", "CptVec"));
	initCpt(contcontdoc, "CptAvl", retrieveTi(srcdoc, "TagWznmVitDetail", "CptAvl"));
	initCpt(contcontdoc, "CptImp", retrieveTi(srcdoc, "TagWznmVitDetail", "CptImp"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmVitDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate");

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

	var height = 342; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxtSrfActive") == "true");

	var PupJActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "PupJActive") == "true");
	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "ButJEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxtTitActive") == "true");

	var TxtVecActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxtVecActive") == "true");
	var ButVecViewAvail = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "ButVecViewAvail") == "true");
	var ButVecViewActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "ButVecViewActive") == "true");

	var TxfAvlActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxfAvlActive") == "true");

	var TxfImpActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxfImpActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmVitDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmVitDetail", "TxtSrf"));

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacWznmVitDetail", "numFPupJ"), PupJActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmVitDetail", "TxtTit"));

	if ((ButVecViewAvail == !contcontdoc.getElementById("ButVecView"))) {
		mytd = contcontdoc.getElementById("rdynVec");
		clearElem(mytd);

		first = true;

		if (ButVecViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVecView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtVec", retrieveCi(srcdoc, "ContInfWznmVitDetail", "TxtVec"));

	if (ButVecViewAvail) refreshButicon(contcontdoc, "ButVecView", "icon/view", ButVecViewActive, false);

	refreshTxft(contcontdoc, "TxfAvl", retrieveCi(srcdoc, "ContIacWznmVitDetail", "TxfAvl"), TxfAvlActive, false, true);

	refreshTxft(contcontdoc, "TxfImp", retrieveCi(srcdoc, "ContIacWznmVitDetail", "TxfImp"), TxfImpActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmVitDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVitDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVitDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVitDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVitDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmVitDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVitDetailData", scrJref, "ContIacWznmVitDetail");
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

	setCi(srcdoc, "ContIacWznmVitDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVitDetailData", scrJref, "ContIacWznmVitDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "ContIacWznmVitDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "ContInfWznmVitDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "StatAppWznmVitDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "StatShrWznmVitDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVitDetailData", "TagWznmVitDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmVitDetailData") {
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
			if (blk.nodeName == "DpchEngWznmVitDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmVitDetailData") {
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
