/**
  * \file PnlWznmSbsDetail.js
  * web client functionality for panel PnlWznmSbsDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmSbsDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSbsDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmSbsDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmSbsDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmSbsDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSho", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptSho"));
	initCpt(contcontdoc, "CptTbl", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptTbl"));
	initCpt(contcontdoc, "CptCar", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptCar"));
	initCpt(contcontdoc, "CptCnd", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptCnd"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptCmt"));
	initCpt(contcontdoc, "CptPstSrf", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptPstSrf"));
	initCpt(contcontdoc, "CptPstTit", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptPstTit"));
	initCpt(contcontdoc, "CptPstVer", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptPstVer"));
	initCpt(contcontdoc, "CptPstSco", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptPstSco"));
	refreshPup(contcontdoc, srcdoc, "PupPstSco", "", "FeedFPupPstSco", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "numFPupPstSco"), retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstScoActive"), false);
	initCpt(contcontdoc, "CptPstAty", retrieveTi(srcdoc, "TagWznmSbsDetail", "CptPstAty"));
	refreshPup(contcontdoc, srcdoc, "PupPstAty", "", "FeedFPupPstAty", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "numFPupPstAty"), retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstAtyActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate");

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

	var height = 449; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtSrfActive") == "true");

	var TxfShoActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxfShoActive") == "true");

	var TxtTblActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtTblActive") == "true");

	var TxtCarActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtCarActive") == "true");
	var ButCarViewAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButCarViewAvail") == "true");
	var ButCarViewActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButCarViewActive") == "true");

	var TxfCndActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxfCndActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxfCmtActive") == "true");

	var ButPstNewAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButPstNewAvail") == "true");
	var ButPstDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButPstDeleteAvail") == "true");

	var TxtPstSrfAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstSrfAvail") == "true");
	var TxtPstSrfActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstSrfActive") == "true");

	var PupPstJtiAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstJtiAvail") == "true");
	var PupPstJtiActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstJtiActive") == "true");
	var ButPstJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButPstJtiEditAvail") == "true");

	var TxtPstTitAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstTitAvail") == "true");
	var TxtPstTitActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstTitActive") == "true");

	var TxtPstVerAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstVerAvail") == "true");
	var TxtPstVerActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "TxtPstVerActive") == "true");
	var ButPstVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButPstVerViewAvail") == "true");
	var ButPstVerViewActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButPstVerViewActive") == "true");

	var PupPstScoAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstScoAvail") == "true");
	var PupPstScoActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstScoActive") == "true");

	var PupPstAtyAvail = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstAtyAvail") == "true");
	var PupPstAtyActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "PupPstAtyActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmSbsDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfSho", "xs", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "TxfSho"), TxfShoActive, false, true);

	refreshTxt(contcontdoc, "TxtTbl", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtTbl"));

	if ((ButCarViewAvail == !contcontdoc.getElementById("ButCarView"))) {
		mytd = contcontdoc.getElementById("rdynCar");
		clearElem(mytd);

		first = true;

		if (ButCarViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCarView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCar", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtCar"));

	if (ButCarViewAvail) refreshButicon(contcontdoc, "ButCarView", "icon/view", ButCarViewActive, false);

	refreshTxft(contcontdoc, "TxfCnd", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "TxfCnd"), TxfCndActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButPstNewAvail == !contcontdoc.getElementById("ButPstNew")) || (ButPstDeleteAvail == !contcontdoc.getElementById("ButPstDelete"))) {
		mytd = contcontdoc.getElementById("dynPst");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgPst", retrieveTi(srcdoc, "TagWznmSbsDetail", "HdgPst")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButPstNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstNew", "icon/new"));
		};

		if (ButPstDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "PstSrf", TxtPstSrfAvail, 25);
	if (TxtPstSrfAvail) {
		refreshTxt(contcontdoc, "TxtPstSrf", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtPstSrf"));

	};

	height -= setCtlAvail(contcontdoc, "PstJti", PupPstJtiAvail, 25);
	if (PupPstJtiAvail) {
		if ((ButPstJtiEditAvail == !contcontdoc.getElementById("ButPstJtiEdit"))) {
			mytd = contcontdoc.getElementById("rdynPstJti");
			clearElem(mytd);

			first = true;

			if (ButPstJtiEditAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstJtiEdit", "icon/edit"));
			};
		};

		refreshPup(contcontdoc, srcdoc, "PupPstJti", "s", "FeedFPupPstJti", retrieveCi(srcdoc, "ContIacWznmSbsDetail", "numFPupPstJti"), PupPstJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstTit", TxtPstTitAvail, 25);
	if (TxtPstTitAvail) {
		refreshTxt(contcontdoc, "TxtPstTit", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtPstTit"));

	};

	height -= setCtlAvail(contcontdoc, "PstVer", TxtPstVerAvail, 25);
	if (TxtPstVerAvail) {
		if ((ButPstVerViewAvail == !contcontdoc.getElementById("ButPstVerView"))) {
			mytd = contcontdoc.getElementById("rdynPstVer");
			clearElem(mytd);

			first = true;

			if (ButPstVerViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstVerView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtPstVer", retrieveCi(srcdoc, "ContInfWznmSbsDetail", "TxtPstVer"));

		if (ButPstVerViewAvail) refreshButicon(contcontdoc, "ButPstVerView", "icon/view", ButPstVerViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstSco", PupPstScoAvail, 25);
	if (PupPstScoAvail) {
		contcontdoc.getElementById("PupPstSco").value = retrieveCi(srcdoc, "ContIacWznmSbsDetail", "numFPupPstSco");

	};

	height -= setCtlAvail(contcontdoc, "PstAty", PupPstAtyAvail, 25);
	if (PupPstAtyAvail) {
		contcontdoc.getElementById("PupPstAty").value = retrieveCi(srcdoc, "ContIacWznmSbsDetail", "numFPupPstAty");

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmSbsDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSbsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSbsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSbsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmSbsDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSbsDetailData", scrJref, "ContIacWznmSbsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmSbsDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmSbsDetailData", scrJref, "ContIacWznmSbsDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmSbsDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSbsDetailData", scrJref, "ContIacWznmSbsDetail");
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

	setCi(srcdoc, "ContIacWznmSbsDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmSbsDetailData", scrJref, "ContIacWznmSbsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "ContIacWznmSbsDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "ContInfWznmSbsDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "FeedFPupPstAty", srcdoc)) mask.push("feedFPupPstAty");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "FeedFPupPstJti", srcdoc)) mask.push("feedFPupPstJti");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "FeedFPupPstSco", srcdoc)) mask.push("feedFPupPstSco");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "StatAppWznmSbsDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "StatShrWznmSbsDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmSbsDetailData", "TagWznmSbsDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmSbsDetailData") {
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
			if (blk.nodeName == "DpchEngWznmSbsDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmSbsDetailData") {
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

