// IP cust --- INSERT

// --- view initialization and refresh
function initWri() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWri --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmMchWriniscrWri", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmMchWriniscrWri", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmMchWriniscrWri", "ButSto"));
	// IP initWri --- END

	setSi(srcdoc, "StatAppDlgWznmMchWriniscr", "initdone", "true");

	refreshWri();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmMchWriniscrFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWznmMchWriniscr", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmMchWriniscr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmMchWriniscr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmMchWriniscr", "numFDse"));

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

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmMchWriniscrWri", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmMchWriniscrWri", "ButStoActive") == "true");

	// IP refreshWri.vars --- END

	// IP refreshWri --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmMchWriniscrWri", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWri --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmMchWriniscrFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmMchWriniscrFia", "Dld"), DldActive);

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmMchWriniscr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmMchWriniscr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmMchWriniscr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmMchWriniscr" + shortDit + ".xml" 

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
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmMchWriniscrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmMchWriniscr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmMchWriniscr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmMchWriniscr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmMchWriniscrData", scrJref, "ContIacDlgWznmMchWriniscr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "ContIacDlgWznmMchWriniscr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "ContInfDlgWznmMchWriniscr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "ContInfDlgWznmMchWriniscrFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "ContInfDlgWznmMchWriniscrWri", srcdoc)) mask.push("continfwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "StatAppDlgWznmMchWriniscr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "StatShrDlgWznmMchWriniscr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "StatShrDlgWznmMchWriniscrFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "StatShrDlgWznmMchWriniscrWri", srcdoc)) mask.push("statshrwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "TagDlgWznmMchWriniscr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "TagDlgWznmMchWriniscrFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmMchWriniscrData", "TagDlgWznmMchWriniscrWri", srcdoc)) mask.push("tagwri");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmMchWriniscrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmMchWriniscrData") {
		handleDpchEngDlgWznmMchWriniscrData(dom);
	};
};

function handleDpchEngDlgWznmMchWriniscrData(dom) {
	// IP handleDpchEngDlgWznmMchWriniscrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmMchWriniscrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmMchWriniscrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

