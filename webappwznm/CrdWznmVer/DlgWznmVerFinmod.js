// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVerFinmod", "Cpt"));

	initCpt(contdoc, "FnmCptPrg", retrieveTi(srcdoc, "TagDlgWznmVerFinmod", "FnmCptPrg"));
	initBut(contdoc, "FnmButRun", retrieveTi(srcdoc, "TagDlgWznmVerFinmod", "FnmButRun"));
	initBut(contdoc, "FnmButSto", retrieveTi(srcdoc, "TagDlgWznmVerFinmod", "FnmButSto"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmVerFinmod", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var FnmButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerFinmod", "FnmButRunActive") == "true");
	var FnmButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerFinmod", "FnmButStoActive") == "true");

	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerFinmod", "ButDneActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxtt(contdoc, "FnmTxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVerFinmod", "FnmTxtPrg"));

	refreshBut(contdoc, "FnmButRun", FnmButRunActive, false);
	refreshBut(contdoc, "FnmButSto", FnmButStoActive, false);

	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmVerFinmodDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVerFinmodData", "ContInfDlgWznmVerFinmod", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerFinmodData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerFinmodData", "StatAppDlgWznmVerFinmod", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerFinmodData", "StatShrDlgWznmVerFinmod", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerFinmodData", "TagDlgWznmVerFinmod", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmVerFinmodData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmVerFinmodData") {
		handleDpchEngDlgWznmVerFinmodData(dom);
	};
};

function handleDpchEngDlgWznmVerFinmodData(dom) {
	// IP handleDpchEngDlgWznmVerFinmodData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVerFinmodData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngWznmAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
							retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
							retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgWznmVerFinmodData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
