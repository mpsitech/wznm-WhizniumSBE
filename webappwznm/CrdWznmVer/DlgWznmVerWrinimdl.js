// IP cust --- INSERT

// --- view initialization and refresh
function initWri() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWri --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmVerWrinimdlWri", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmVerWrinimdlWri", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmVerWrinimdlWri", "ButSto"));
	// IP initWri --- END

	setSi(srcdoc, "StatAppDlgWznmVerWrinimdl", "initdone", "true");

	refreshWri();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmVerWrinimdlFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWznmVerWrinimdl", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVerWrinimdl", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmVerWrinimdl", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerWrinimdl", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 2; num++) {
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

function refreshWri() {
	// IP refreshWri.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerWrinimdlWri", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerWrinimdlWri", "ButStoActive") == "true");

	// IP refreshWri.vars --- END

	// IP refreshWri --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVerWrinimdlWri", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWri --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerWrinimdlFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmVerWrinimdlFia", "Dld"), DldActive);

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmVerWrinimdl", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmVerWrinimdl", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerWrinimdl", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmVerWrinimdl" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Wri") {
			refreshWri();
		} else if (shortDit == "Fia") {
			refreshFia();
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

// --- specific event handlers for app controls of dialog item Wri

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmVerWrinimdlDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerWrinimdl", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmVerWrinimdl", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmVerWrinimdl", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerWrinimdlData", scrJref, "ContIacDlgWznmVerWrinimdl");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "ContIacDlgWznmVerWrinimdl", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "ContInfDlgWznmVerWrinimdl", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "ContInfDlgWznmVerWrinimdlFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "ContInfDlgWznmVerWrinimdlWri", srcdoc)) mask.push("continfwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "StatAppDlgWznmVerWrinimdl", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "StatShrDlgWznmVerWrinimdl", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "StatShrDlgWznmVerWrinimdlFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "StatShrDlgWznmVerWrinimdlWri", srcdoc)) mask.push("statshrwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "TagDlgWznmVerWrinimdl", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "TagDlgWznmVerWrinimdlFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerWrinimdlData", "TagDlgWznmVerWrinimdlWri", srcdoc)) mask.push("tagwri");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmVerWrinimdlData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmVerWrinimdlData") {
		handleDpchEngDlgWznmVerWrinimdlData(dom);
	};
};

function handleDpchEngDlgWznmVerWrinimdlData(dom) {
	// IP handleDpchEngDlgWznmVerWrinimdlData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVerWrinimdlData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVerWrinimdlData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
