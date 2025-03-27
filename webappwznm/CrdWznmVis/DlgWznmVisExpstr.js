// IP cust --- INSERT

// --- view initialization and refresh
function initWri() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWri --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmVisExpstrWri", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmVisExpstrWri", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmVisExpstrWri", "ButSto"));
	// IP initWri --- END

	setSi(srcdoc, "StatAppDlgWznmVisExpstr", "initdone", "true");

	refreshWri();
};

function initMfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initMfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmVisExpstrMfi", "Dld"));
	// IP initMfi --- END

	setSi(srcdoc, "StatAppDlgWznmVisExpstr", "initdone", "true");

	refreshMfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVisExpstr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmVisExpstr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVisExpstr", "numFDse"));

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

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisExpstrWri", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisExpstrWri", "ButStoActive") == "true");

	// IP refreshWri.vars --- END

	// IP refreshWri --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVisExpstrWri", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWri --- END
};

function refreshMfi() {
	// IP refreshMfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisExpstrMfi", "DldActive") == "true");

	// IP refreshMfi.vars --- END

	// IP refreshMfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmVisExpstrMfi", "Dld"), DldActive);

	// IP refreshMfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmVisExpstr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmVisExpstr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmVisExpstr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmVisExpstr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Wri") {
			refreshWri();
		} else if (shortDit == "Mfi") {
			refreshMfi();
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

// --- specific event handlers for app controls of dialog item Mfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmVisExpstrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVisExpstr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmVisExpstr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmVisExpstr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVisExpstrData", scrJref, "ContIacDlgWznmVisExpstr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "ContIacDlgWznmVisExpstr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "ContInfDlgWznmVisExpstr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "ContInfDlgWznmVisExpstrMfi", srcdoc)) mask.push("continfmfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "ContInfDlgWznmVisExpstrWri", srcdoc)) mask.push("continfwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "StatAppDlgWznmVisExpstr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "StatShrDlgWznmVisExpstr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "StatShrDlgWznmVisExpstrMfi", srcdoc)) mask.push("statshrmfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "StatShrDlgWznmVisExpstrWri", srcdoc)) mask.push("statshrwri");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "TagDlgWznmVisExpstr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "TagDlgWznmVisExpstrMfi", srcdoc)) mask.push("tagmfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVisExpstrData", "TagDlgWznmVisExpstrWri", srcdoc)) mask.push("tagwri");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmVisExpstrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmVisExpstrData") {
		handleDpchEngDlgWznmVisExpstrData(dom);
	};
};

function handleDpchEngDlgWznmVisExpstrData(dom) {
	// IP handleDpchEngDlgWznmVisExpstrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVisExpstrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVisExpstrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
