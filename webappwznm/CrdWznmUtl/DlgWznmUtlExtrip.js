/**
  * \file DlgWznmUtlExtrip.js
  * web client functionality for dialog DlgWznmUtlExtrip
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initSrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initSrc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmUtlExtripSrc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmUtlExtripSrc", "Uld");
	// IP initSrc --- END

	setSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone", "true");

	refreshSrc();
};

function initExt() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initExt --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmUtlExtripExt", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmUtlExtripExt", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmUtlExtripExt", "ButSto"));
	// IP initExt --- END

	setSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone", "true");

	refreshExt();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmUtlExtripLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone", "true");

	refreshLfi();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmUtlExtripRes", "Dld"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmUtlExtrip", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmUtlExtrip", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlExtrip", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 4; num++) {
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
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtripSrc", "UldActive") == "true");

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

function refreshExt() {
	// IP refreshExt.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtripExt", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtripExt", "ButStoActive") == "true");

	// IP refreshExt.vars --- END

	// IP refreshExt --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmUtlExtripExt", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshExt --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtripLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUtlExtripLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtripRes", "DldActive") == "true");

	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUtlExtripRes", "Dld"), DldActive);

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmUtlExtrip", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmUtlExtrip", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmUtlExtrip" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Src") {
			refreshSrc();
		} else if (shortDit == "Ext") {
			refreshExt();
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

// --- specific event handlers for app controls of dialog item Ext

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmUtlExtripDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmUtlExtrip", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmUtlExtrip", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmUtlExtrip", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmUtlExtripData", scrJref, "ContIacDlgWznmUtlExtrip");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "ContIacDlgWznmUtlExtrip", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "ContInfDlgWznmUtlExtrip", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "ContInfDlgWznmUtlExtripExt", srcdoc)) mask.push("continfext");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "ContInfDlgWznmUtlExtripLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "ContInfDlgWznmUtlExtripRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatAppDlgWznmUtlExtrip", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatShrDlgWznmUtlExtrip", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatShrDlgWznmUtlExtripExt", srcdoc)) mask.push("statshrext");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatShrDlgWznmUtlExtripLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatShrDlgWznmUtlExtripRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "StatShrDlgWznmUtlExtripSrc", srcdoc)) mask.push("statshrsrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "TagDlgWznmUtlExtrip", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "TagDlgWznmUtlExtripExt", srcdoc)) mask.push("tagext");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "TagDlgWznmUtlExtripLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "TagDlgWznmUtlExtripRes", srcdoc)) mask.push("tagres");
	if (updateSrcblock(dom, "DpchEngDlgWznmUtlExtripData", "TagDlgWznmUtlExtripSrc", srcdoc)) mask.push("tagsrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmUtlExtripData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmUtlExtripData") {
		handleDpchEngDlgWznmUtlExtripData(dom);
	};
};

function handleDpchEngDlgWznmUtlExtripData(dom) {
	// IP handleDpchEngDlgWznmUtlExtripData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmUtlExtripData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmUtlExtripData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

