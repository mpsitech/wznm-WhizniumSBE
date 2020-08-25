/**
  * \file DlgWznmAppNew.js
  * web client functionality for dialog DlgWznmAppNew
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmAppNew", "Cpt"));

	initCpt(contdoc, "DetCptTrg", retrieveTi(srcdoc, "TagDlgWznmAppNew", "DetCptTrg"));
	refreshPup(contdoc, srcdoc, "DetPupTrg", "", "FeedFDetPupTrg", retrieveCi(srcdoc, "ContIacDlgWznmAppNew", "numFDetPupTrg"), true, false);
	initCpt(contdoc, "DetCptVer", retrieveTi(srcdoc, "TagDlgWznmAppNew", "DetCptVer"));
	initCpt(contdoc, "DetCptSho", retrieveTi(srcdoc, "TagDlgWznmAppNew", "DetCptSho"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgWznmAppNew", "DetCptTit"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWznmAppNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWznmAppNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	contdoc.getElementById("DetPupTrg").value = retrieveCi(srcdoc, "ContIacDlgWznmAppNew", "numFDetPupTrg");

	refreshPup(contdoc, srcdoc, "DetPupVer", "", "FeedFDetPupVer", retrieveCi(srcdoc, "ContIacDlgWznmAppNew", "numFDetPupVer"), true, false);

	refreshTxf(contdoc, "DetTxfSho", "s", retrieveCi(srcdoc, "ContIacDlgWznmAppNew", "DetTxfSho"), true, false, true);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgWznmAppNew", "DetTxfTit"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmAppNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmAppNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmAppNewData", scrJref, "ContIacDlgWznmAppNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWznmAppNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmAppNewData", scrJref, "ContIacDlgWznmAppNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWznmAppNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmAppNewData", scrJref, "ContIacDlgWznmAppNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "ContIacDlgWznmAppNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "ContInfDlgWznmAppNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "FeedFDetPupTrg", srcdoc)) mask.push("feedFDetPupTrg");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "FeedFDetPupVer", srcdoc)) mask.push("feedFDetPupVer");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "StatAppDlgWznmAppNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "StatShrDlgWznmAppNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppNewData", "TagDlgWznmAppNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmAppNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmAppNewData") {
		handleDpchEngDlgWznmAppNewData(dom);
	};
};

function handleDpchEngDlgWznmAppNewData(dom) {
	// IP handleDpchEngDlgWznmAppNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmAppNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmAppNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

