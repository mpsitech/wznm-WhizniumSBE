// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmTagDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTagDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmTagDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTagDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmTagDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmTagDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmTagDetail", "CptTit"));
	initCpt(contcontdoc, "CptCpb", retrieveTi(srcdoc, "TagWznmTagDetail", "CptCpb"));
	initCpt(contcontdoc, "CptGrp", retrieveTi(srcdoc, "TagWznmTagDetail", "CptGrp"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate");

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

	var height = 142; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "TxtSrfActive") == "true");

	var PupJtiActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "PupJtiActive") == "true");
	var ButJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "ButJtiEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "TxtTitActive") == "true");

	var TxtCpbActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "TxtCpbActive") == "true");
	var ButCpbViewAvail = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "ButCpbViewAvail") == "true");
	var ButCpbViewActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "ButCpbViewActive") == "true");

	var PupGrpAlt = (retrieveSi(srcdoc, "StatAppWznmTagDetail", "PupGrpAlt") == "true");
	var TxfGrpValid = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "TxfGrpValid") == "true");
	var PupGrpActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "PupGrpActive") == "true");
	var ButGrpEditAvail = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "ButGrpEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmTagDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmTagDetail", "TxtSrf"));

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

	refreshPup(contcontdoc, srcdoc, "PupJti", "s", "FeedFPupJti", retrieveCi(srcdoc, "ContIacWznmTagDetail", "numFPupJti"), PupJtiActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmTagDetail", "TxtTit"));

	if ((ButCpbViewAvail == !contcontdoc.getElementById("ButCpbView"))) {
		mytd = contcontdoc.getElementById("rdynCpb");
		clearElem(mytd);

		first = true;

		if (ButCpbViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCpbView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCpb", retrieveCi(srcdoc, "ContInfWznmTagDetail", "TxtCpb"));

	if (ButCpbViewAvail) refreshButicon(contcontdoc, "ButCpbView", "icon/view", ButCpbViewActive, false);

	if ( (PupGrpAlt == !contcontdoc.getElementById("TxfGrp")) || (!PupGrpAlt == !contcontdoc.getElementById("PupGrp")) ) {
		mytd = contcontdoc.getElementById("dynGrp");
		clearElem(mytd);

		if (PupGrpAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfGrp", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupGrp", ""));
	};

	if (PupGrpAlt) refreshTxf(contcontdoc, "TxfGrp", "", retrieveCi(srcdoc, "ContIacWznmTagDetail", "TxfGrp"), PupGrpActive, false, TxfGrpValid);
	else refreshPup(contcontdoc, srcdoc, "PupGrp", "", "FeedFPupGrp", retrieveCi(srcdoc, "ContIacWznmTagDetail", "numFPupGrp"), true, false);

	if ((ButGrpEditAvail == !contcontdoc.getElementById("ButGrpEdit"))) {
		mytd = contcontdoc.getElementById("rdynGrp");
		clearElem(mytd);

		first = true;

		if (ButGrpEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButGrpEdit", "icon/edit"));
		};
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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTagDetail", "srefIxWznmVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWznmTagDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWznmTagDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTagDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTagDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTagDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmTagDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTagDetailData", scrJref, "ContIacWznmTagDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmTagDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmTagDetailData", scrJref, "ContIacWznmTagDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmTagDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTagDetailData", scrJref, "ContIacWznmTagDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "ContIacWznmTagDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "ContInfWznmTagDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "FeedFPupGrp", srcdoc)) mask.push("feedFPupGrp");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "FeedFPupJti", srcdoc)) mask.push("feedFPupJti");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "StatAppWznmTagDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "StatShrWznmTagDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmTagDetailData", "TagWznmTagDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmTagDetailData") {
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
			if (blk.nodeName == "DpchEngWznmTagDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmTagDetailData") {
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
