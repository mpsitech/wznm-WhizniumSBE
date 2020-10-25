/**
  * \file DlgWznmUtlMrgip.js
  * web client functionality for dialog DlgWznmUtlMrgip
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initSrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initSrc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmUtlMrgipSrc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmUtlMrgipSrc", "Uld");
	// IP initSrc --- END

	setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "true");

	refreshSrc();
};

function initTrg() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initTrg --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmUtlMrgipTrg", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmUtlMrgipTrg", "Uld");
	// IP initTrg --- END

	setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "true");

	refreshTrg();
};

function initMrg() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initMrg --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmUtlMrgipMrg", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmUtlMrgipMrg", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmUtlMrgipMrg", "ButSto"));
	// IP initMrg --- END

	setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "true");

	refreshMrg();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmUtlMrgipLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "true");

	refreshLfi();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmUtlMrgipRes", "Dld"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmUtlMrgip", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmUtlMrgip", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlMrgip", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 5; num++) {
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
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipSrc", "UldActive") == "true");

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

function refreshTrg() {
	// IP refreshTrg.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipTrg", "UldActive") == "true");

	// IP refreshTrg.vars --- END

	// IP refreshTrg --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshTrg --- END
};

function refreshMrg() {
	// IP refreshMrg.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipMrg", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipMrg", "ButStoActive") == "true");

	// IP refreshMrg.vars --- END

	// IP refreshMrg --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmUtlMrgipMrg", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshMrg --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUtlMrgipLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgipRes", "DldActive") == "true");

	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUtlMrgipRes", "Dld"), DldActive);

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmUtlMrgip", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlMrgip", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmUtlMrgip" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Src") {
			refreshSrc();
		} else if (shortDit == "Trg") {
			refreshTrg();
		} else if (shortDit == "Mrg") {
			refreshMrg();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Trg

// --- specific event handlers for app controls of dialog item Mrg

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmUtlMrgipDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlMrgip", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmUtlMrgip", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmUtlMrgip", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmUtlMrgipData", scrJref, "ContIacDlgWznmUtlMrgip");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "ContIacDlgWznmUtlMrgip", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "ContInfDlgWznmUtlMrgip", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "ContInfDlgWznmUtlMrgipLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "ContInfDlgWznmUtlMrgipMrg", srcdoc)) mask.push("continfmrg");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "ContInfDlgWznmUtlMrgipRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatAppDlgWznmUtlMrgip", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgip", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgipLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgipMrg", srcdoc)) mask.push("statshrmrg");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgipRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgipSrc", srcdoc)) mask.push("statshrsrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "StatShrDlgWznmUtlMrgipTrg", srcdoc)) mask.push("statshrtrg");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgip", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgipLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgipMrg", srcdoc)) mask.push("tagmrg");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgipRes", srcdoc)) mask.push("tagres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgipSrc", srcdoc)) mask.push("tagsrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlMrgipData", "TagDlgWznmUtlMrgipTrg", srcdoc)) mask.push("tagtrg");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmUtlMrgipData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmUtlMrgipData") {
		handleDpchEngDlgWznmUtlMrgipData(dom);
	};
};

function handleDpchEngDlgWznmUtlMrgipData(dom) {
	// IP handleDpchEngDlgWznmUtlMrgipData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmUtlMrgipData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmUtlMrgipData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

