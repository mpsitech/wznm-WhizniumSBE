// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmUsrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmUsrDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmUsrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmUsrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmUsrDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptPrs"));
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptUsg"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupSteActive"), false);
	initCpt(contcontdoc, "CptLcl", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptLcl"));
	refreshPup(contcontdoc, srcdoc, "PupLcl", "", "FeedFPupLcl", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupLcl"), retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupLclActive"), false);
	initCpt(contcontdoc, "CptUlv", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptUlv"));
	refreshPup(contcontdoc, srcdoc, "PupUlv", "", "FeedFPupUlv", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupUlv"), retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupUlvActive"), false);
	initCpt(contcontdoc, "CptPwd", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptPwd"));
	initCpt(contcontdoc, "CptFky", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptFky"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmUsrDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate");

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

	var height = 367; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrsActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxtPrsActive") == "true");
	var ButPrsViewAvail = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButPrsViewAvail") == "true");
	var ButPrsViewActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButPrsViewActive") == "true");

	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxtSrfActive") == "true");

	var TxtUsgActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxtUsgActive") == "true");
	var ButUsgViewAvail = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButUsgViewAvail") == "true");
	var ButUsgViewActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButUsgViewActive") == "true");

	var PupJstActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupJstActive") == "true");
	var ButJstEditAvail = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButJstEditAvail") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupSteActive") == "true");

	var PupLclActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupLclActive") == "true");

	var PupUlvActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "PupUlvActive") == "true");

	var TxfPwdActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxfPwdActive") == "true");

	var TxfFkyActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxfFkyActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmUsrDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView"))) {
		mytd = contcontdoc.getElementById("rdynPrs");
		clearElem(mytd);

		first = true;

		if (ButPrsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrs", retrieveCi(srcdoc, "ContInfWznmUsrDetail", "TxtPrs"));

	if (ButPrsViewAvail) refreshButicon(contcontdoc, "ButPrsView", "icon/view", ButPrsViewActive, false);

	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmUsrDetail", "TxtSrf"));

	if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView"))) {
		mytd = contcontdoc.getElementById("rdynUsg");
		clearElem(mytd);

		first = true;

		if (ButUsgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUsg", retrieveCi(srcdoc, "ContInfWznmUsrDetail", "TxtUsg"));

	if (ButUsgViewAvail) refreshButicon(contcontdoc, "ButUsgView", "icon/view", ButUsgViewActive, false);

	if ((ButJstEditAvail == !contcontdoc.getElementById("ButJstEdit"))) {
		mytd = contcontdoc.getElementById("rdynJst");
		clearElem(mytd);

		first = true;

		if (ButJstEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJstEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJst", "s", "FeedFPupJst", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupJst"), PupJstActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupSte");

	contcontdoc.getElementById("PupLcl").value = retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupLcl");

	contcontdoc.getElementById("PupUlv").value = retrieveCi(srcdoc, "ContIacWznmUsrDetail", "numFPupUlv");

	refreshTxf(contcontdoc, "TxfPwd", "s", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "TxfPwd"), TxfPwdActive, false, true);

	refreshTxft(contcontdoc, "TxfFky", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "TxfFky"), TxfFkyActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmUsrDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmUsrDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmUsrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmUsrDetailData", scrJref, "ContIacWznmUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmUsrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmUsrDetailData", scrJref, "ContIacWznmUsrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmUsrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmUsrDetailData", scrJref, "ContIacWznmUsrDetail");
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

	setCi(srcdoc, "ContIacWznmUsrDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmUsrDetailData", scrJref, "ContIacWznmUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "ContIacWznmUsrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "ContInfWznmUsrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "FeedFPupJst", srcdoc)) mask.push("feedFPupJst");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "FeedFPupLcl", srcdoc)) mask.push("feedFPupLcl");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "FeedFPupUlv", srcdoc)) mask.push("feedFPupUlv");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "StatAppWznmUsrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "StatShrWznmUsrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmUsrDetailData", "TagWznmUsrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmUsrDetailData") {
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
			if (blk.nodeName == "DpchEngWznmUsrDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmUsrDetailData") {
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

