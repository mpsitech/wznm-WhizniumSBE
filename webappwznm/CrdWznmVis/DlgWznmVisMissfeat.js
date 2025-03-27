// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVisMissfeat", "Cpt"));

	initCpt(contdoc, "CmfCptPrg", retrieveTi(srcdoc, "TagDlgWznmVisMissfeat", "CmfCptPrg"));
	initBut(contdoc, "CmfButRun", retrieveTi(srcdoc, "TagDlgWznmVisMissfeat", "CmfButRun"));
	initBut(contdoc, "CmfButSto", retrieveTi(srcdoc, "TagDlgWznmVisMissfeat", "CmfButSto"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmVisMissfeat", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var CmfButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisMissfeat", "CmfButRunActive") == "true");
	var CmfButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisMissfeat", "CmfButStoActive") == "true");

	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisMissfeat", "ButDneActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxtt(contdoc, "CmfTxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVisMissfeat", "CmfTxtPrg"));

	refreshBut(contdoc, "CmfButRun", CmfButRunActive, false);
	refreshBut(contdoc, "CmfButSto", CmfButStoActive, false);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmVisMissfeatDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVisMissfeatData", "ContInfDlgWznmVisMissfeat", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisMissfeatData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisMissfeatData", "StatAppDlgWznmVisMissfeat", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisMissfeatData", "StatShrDlgWznmVisMissfeat", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisMissfeatData", "TagDlgWznmVisMissfeat", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmVisMissfeatData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmVisMissfeatData") {
		handleDpchEngDlgWznmVisMissfeatData(dom);
	};
};

function handleDpchEngDlgWznmVisMissfeatData(dom) {
	// IP handleDpchEngDlgWznmVisMissfeatData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVisMissfeatData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVisMissfeatData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
