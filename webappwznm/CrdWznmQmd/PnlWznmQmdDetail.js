/**
  * \file PnlWznmQmdDetail.js
  * web client functionality for panel PnlWznmQmdDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmQmdDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmQmdDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmQmdDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmQmdDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmQmdDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmQmdDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmQmdDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmQmdDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptQry", retrieveTi(srcdoc, "TagWznmQmdDetail", "CptQry"));
	initCpt(contcontdoc, "CptPst", retrieveTi(srcdoc, "TagWznmQmdDetail", "CptPst"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmQmdDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmQmdDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptAvl", retrieveTi(srcdoc, "TagWznmQmdDetail", "CptAvl"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate");

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

	var height = 185; // full cont height

	// IP refreshBD.vars --- BEGIN
	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "PupTypActive") == "true");

	var TxtQryActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "TxtQryActive") == "true");
	var ButQryViewAvail = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButQryViewAvail") == "true");
	var ButQryViewActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButQryViewActive") == "true");

	var TxtPstActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "TxtPstActive") == "true");
	var ButPstViewAvail = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButPstViewAvail") == "true");
	var ButPstViewActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButPstViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButReuViewActive") == "true");

	var TxfAvlActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "TxfAvlActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmQmdDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmQmdDetail", "numFPupTyp");

	if ((ButQryViewAvail == !contcontdoc.getElementById("ButQryView"))) {
		mytd = contcontdoc.getElementById("rdynQry");
		clearElem(mytd);

		first = true;

		if (ButQryViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButQryView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtQry", retrieveCi(srcdoc, "ContInfWznmQmdDetail", "TxtQry"));

	if (ButQryViewAvail) refreshButicon(contcontdoc, "ButQryView", "icon/view", ButQryViewActive, false);

	if ((ButPstViewAvail == !contcontdoc.getElementById("ButPstView"))) {
		mytd = contcontdoc.getElementById("rdynPst");
		clearElem(mytd);

		first = true;

		if (ButPstViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPst", retrieveCi(srcdoc, "ContInfWznmQmdDetail", "TxtPst"));

	if (ButPstViewAvail) refreshButicon(contcontdoc, "ButPstView", "icon/view", ButPstViewActive, false);

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

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmQmdDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmQmdDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	refreshTxft(contcontdoc, "TxfAvl", retrieveCi(srcdoc, "ContIacWznmQmdDetail", "TxfAvl"), TxfAvlActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmQmdDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmQmdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmQmdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmQmdDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmQmdDetailData", scrJref, "ContIacWznmQmdDetail");
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

	setCi(srcdoc, "ContIacWznmQmdDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmQmdDetailData", scrJref, "ContIacWznmQmdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "ContIacWznmQmdDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "ContInfWznmQmdDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "StatAppWznmQmdDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "StatShrWznmQmdDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmQmdDetailData", "TagWznmQmdDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmQmdDetailData") {
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
			if (blk.nodeName == "DpchEngWznmQmdDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmQmdDetailData") {
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

