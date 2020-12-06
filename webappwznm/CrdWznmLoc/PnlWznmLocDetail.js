// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmLocDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmLocDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmLocDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmLocDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmLocDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmLocDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmLocDetail", "CptTit"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate");

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

	var height = 85; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmLocDetail", "TxtSrfActive") == "true");

	var PupJtiActive = (retrieveSi(srcdoc, "StatShrWznmLocDetail", "PupJtiActive") == "true");
	var ButJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmLocDetail", "ButJtiEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmLocDetail", "TxtTitActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmLocDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmLocDetail", "TxtSrf"));

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

	refreshPup(contcontdoc, srcdoc, "PupJti", "s", "FeedFPupJti", retrieveCi(srcdoc, "ContIacWznmLocDetail", "numFPupJti"), PupJtiActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmLocDetail", "TxtTit"));

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmLocDetail", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmLocDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmLocDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmLocDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmLocDetailData", scrJref, "ContIacWznmLocDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "ContIacWznmLocDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "ContInfWznmLocDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "FeedFPupJti", srcdoc)) mask.push("feedFPupJti");
	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "StatAppWznmLocDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "StatShrWznmLocDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmLocDetailData", "TagWznmLocDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmLocDetailData") {
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
			if (blk.nodeName == "DpchEngWznmLocDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmLocDetailData") {
				mergeDpchEngData(dom);
				refresh();
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
