/**
  * \file PnlWznmNavAuxfct.js
  * web client functionality for panel PnlWznmNavAuxfct
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Auxfct", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Auxfct_side").setAttribute("height", "30");
	doc.getElementById("Auxfct_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Auxfct_side").src = "./PnlWznmNavAuxfct_aside.html";
	doc.getElementById("Auxfct_cont").src = "./PnlWznmNavAuxfct_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Auxfct_side").src = "./PnlWznmNavAuxfct_bside.html";
	doc.getElementById("Auxfct_cont").src = "./PnlWznmNavAuxfct_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Auxfct_side").contentDocument;
	contdoc = doc.getElementById("Auxfct_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavAuxfct", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Auxfct_side").contentDocument;
	contdoc = doc.getElementById("Auxfct_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Auxfct_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Auxfct_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavAuxfct", "Cpt"));
	initCpt(contcontdoc, "CptUtl", retrieveTi(srcdoc, "TagWznmNavAuxfct", "CptUtl"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate");

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

	var height = 35; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButUtlNewcrdAvail = (retrieveSi(srcdoc, "StatShrWznmNavAuxfct", "ButUtlNewcrdAvail") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Utl", ButUtlNewcrdAvail, 25);
	if (ButUtlNewcrdAvail) {
		if ((ButUtlNewcrdAvail == !contcontdoc.getElementById("ButUtlNewcrd"))) {
			mytd = contcontdoc.getElementById("dynUtl");
			clearElem(mytd);

			first = true;

			if (ButUtlNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUtlNewcrd", "icon/newcrd"));
			};
		};

	};

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Auxfct", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Auxfct_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Auxfct_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Auxfct_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavAuxfct", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Auxfct_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavAuxfctDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavAuxfctDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavAuxfctData", "StatAppWznmNavAuxfct", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavAuxfctData", "StatShrWznmNavAuxfct", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavAuxfctData", "TagWznmNavAuxfct", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavAuxfctData") {
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
			if (blk.nodeName == "DpchEngWznmNavAuxfctData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Auxfct");
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

			} else if (blk.nodeName == "DpchEngWznmNavAuxfctData") {
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

