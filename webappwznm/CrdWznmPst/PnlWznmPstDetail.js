/**
  * \file PnlWznmPstDetail.js
  * web client functionality for panel PnlWznmPstDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmPstDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmPstDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmPstDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmPstDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmPstDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmPstDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmPstDetail", "CptTit"));
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmPstDetail", "CptVer"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmPstDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptSco", retrieveTi(srcdoc, "TagWznmPstDetail", "CptSco"));
	refreshPup(contcontdoc, srcdoc, "PupSco", "", "FeedFPupSco", retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupSco"), retrieveSi(srcdoc, "StatShrWznmPstDetail", "PupScoActive"), false);
	initCpt(contcontdoc, "CptAty", retrieveTi(srcdoc, "TagWznmPstDetail", "CptAty"));
	refreshPup(contcontdoc, srcdoc, "PupAty", "", "FeedFPupAty", retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupAty"), retrieveSi(srcdoc, "StatShrWznmPstDetail", "PupAtyActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "TxtSrfActive") == "true");

	var PupJtiActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "PupJtiActive") == "true");
	var ButJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButJtiEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "TxtTitActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButVerViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButReuViewActive") == "true");

	var PupScoActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "PupScoActive") == "true");

	var PupAtyActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "PupAtyActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmPstDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmPstDetail", "TxtSrf"));

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

	refreshPup(contcontdoc, srcdoc, "PupJti", "s", "FeedFPupJti", retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupJti"), PupJtiActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmPstDetail", "TxtTit"));

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

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmPstDetail", "TxtVer"));

	if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

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

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmPstDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	contcontdoc.getElementById("PupSco").value = retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupSco");

	contcontdoc.getElementById("PupAty").value = retrieveCi(srcdoc, "ContIacWznmPstDetail", "numFPupAty");

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmPstDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmPstDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmPstDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmPstDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmPstDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmPstDetailData", scrJref, "ContIacWznmPstDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "ContIacWznmPstDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "ContInfWznmPstDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "FeedFPupAty", srcdoc)) mask.push("feedFPupAty");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "FeedFPupJti", srcdoc)) mask.push("feedFPupJti");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "FeedFPupSco", srcdoc)) mask.push("feedFPupSco");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "StatAppWznmPstDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "StatShrWznmPstDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmPstDetailData", "TagWznmPstDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmPstDetailData") {
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
			if (blk.nodeName == "DpchEngWznmPstDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmPstDetailData") {
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

