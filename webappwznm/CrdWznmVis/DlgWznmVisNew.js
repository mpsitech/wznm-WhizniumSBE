// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVisNew", "Cpt"));

	initCpt(contdoc, "DetCptTyp", retrieveTi(srcdoc, "TagDlgWznmVisNew", "DetCptTyp"));
	refreshPup(contdoc, srcdoc, "DetPupTyp", "", "FeedFDetPupTyp", retrieveCi(srcdoc, "ContIacDlgWznmVisNew", "numFDetPupTyp"), true, false);
	initCpt(contdoc, "DetCptVer", retrieveTi(srcdoc, "TagDlgWznmVisNew", "DetCptVer"));
	initCpt(contdoc, "DetCptCmt", retrieveTi(srcdoc, "TagDlgWznmVisNew", "DetCptCmt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWznmVisNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWznmVisNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	contdoc.getElementById("DetPupTyp").value = retrieveCi(srcdoc, "ContIacDlgWznmVisNew", "numFDetPupTyp");

	refreshPup(contdoc, srcdoc, "DetPupVer", "", "FeedFDetPupVer", retrieveCi(srcdoc, "ContIacDlgWznmVisNew", "numFDetPupVer"), true, false);

	refreshTxft(contdoc, "DetTxfCmt", retrieveCi(srcdoc, "ContIacDlgWznmVisNew", "DetTxfCmt"), true, false, true);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmVisNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmVisNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVisNewData", scrJref, "ContIacDlgWznmVisNew");
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

	setCi(srcdoc, "ContIacDlgWznmVisNew", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVisNewData", scrJref, "ContIacDlgWznmVisNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "ContIacDlgWznmVisNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "ContInfDlgWznmVisNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "FeedFDetPupTyp", srcdoc)) mask.push("feedFDetPupTyp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "FeedFDetPupVer", srcdoc)) mask.push("feedFDetPupVer");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "StatAppDlgWznmVisNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "StatShrDlgWznmVisNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisNewData", "TagDlgWznmVisNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmVisNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmVisNewData") {
		handleDpchEngDlgWznmVisNewData(dom);
	};
};

function handleDpchEngDlgWznmVisNewData(dom) {
	// IP handleDpchEngDlgWznmVisNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVisNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVisNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
