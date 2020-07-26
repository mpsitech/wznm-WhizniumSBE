/**
  * \file DlgWznmUtlIexconv.js
  * web client functionality for dialog DlgWznmUtlIexconv
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initSrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initSrc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmUtlIexconvSrc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmUtlIexconvSrc", "Uld");
	// IP initSrc --- END

	setSi(srcdoc, "StatAppDlgWznmUtlIexconv", "initdone", "true");

	refreshSrc();
};

function initCnv() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCnv --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmUtlIexconvCnv", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmUtlIexconvCnv", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmUtlIexconvCnv", "ButSto"));
	// IP initCnv --- END

	setSi(srcdoc, "StatAppDlgWznmUtlIexconv", "initdone", "true");

	refreshCnv();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmUtlIexconvRes", "Dld"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWznmUtlIexconv", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmUtlIexconv", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmUtlIexconv", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlIexconv", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 3; num++) {
		sref = retrieveValue(srcdoc, "//wznm:FeedFDse/wznm:Fi[@num='" + num + "']/wznm:sref");
		Title = retrieveValue(srcdoc, "//wznm:FeedFDse/wznm:Fi[@num='" + num + "']/wznm:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshSrc() {
	// IP refreshSrc.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlIexconvSrc", "UldActive") == "true");

	// IP refreshSrc.vars --- END

	// IP refreshSrc --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshSrc --- END
};

function refreshCnv() {
	// IP refreshCnv.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlIexconvCnv", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlIexconvCnv", "ButStoActive") == "true");

	// IP refreshCnv.vars --- END

	// IP refreshCnv --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmUtlIexconvCnv", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshCnv --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlIexconvRes", "DldActive") == "true");

	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUtlIexconvRes", "Dld"), DldActive);

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmUtlIexconv", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmUtlIexconv", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlIexconv", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmUtlIexconv" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Src") {
			refreshSrc();
		} else if (shortDit == "Cnv") {
			refreshCnv();
		} else if (shortDit == "Res") {
			refreshRes();
		};
	};

	// IP refresh --- BEGIN
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

// --- specific event handlers for app controls of dialog item Src

// --- specific event handlers for app controls of dialog item Cnv

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmUtlIexconvDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlIexconv", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmUtlIexconv", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmUtlIexconv", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmUtlIexconvData", scrJref, "ContIacDlgWznmUtlIexconv");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "ContIacDlgWznmUtlIexconv", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "ContInfDlgWznmUtlIexconv", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "ContInfDlgWznmUtlIexconvCnv", srcdoc)) mask.push("continfcnv");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "ContInfDlgWznmUtlIexconvRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "StatAppDlgWznmUtlIexconv", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "StatShrDlgWznmUtlIexconv", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "StatShrDlgWznmUtlIexconvCnv", srcdoc)) mask.push("statshrcnv");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "StatShrDlgWznmUtlIexconvRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "StatShrDlgWznmUtlIexconvSrc", srcdoc)) mask.push("statshrsrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "TagDlgWznmUtlIexconv", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "TagDlgWznmUtlIexconvCnv", srcdoc)) mask.push("tagcnv");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "TagDlgWznmUtlIexconvRes", srcdoc)) mask.push("tagres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlIexconvData", "TagDlgWznmUtlIexconvSrc", srcdoc)) mask.push("tagsrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmUtlIexconvData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmUtlIexconvData") {
		handleDpchEngDlgWznmUtlIexconvData(dom);
	};
};

function handleDpchEngDlgWznmUtlIexconvData(dom) {
	// IP handleDpchEngDlgWznmUtlIexconvData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmUtlIexconvData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

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

			} else if (blk.nodeName == "DpchEngDlgWznmUtlIexconvData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

