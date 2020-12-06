// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmVerImpexpIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmVerImpexpIfi", "Uld");
	// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmVerImpexpImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmVerImpexpImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmVerImpexpImp", "ButSto"));
	// IP initImp --- END

	setSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone", "true");

	refreshImp();
};

function initPpr() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initPpr --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmVerImpexpPpr", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmVerImpexpPpr", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmVerImpexpPpr", "ButSto"));
	// IP initPpr --- END

	setSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone", "true");

	refreshPpr();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmVerImpexpLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVerImpexp", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmVerImpexp", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerImpexp", "numFDse"));

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

function refreshIfi() {
	// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpIfi", "UldActive") == "true");

	// IP refreshIfi.vars --- END

	// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshIfi --- END
};

function refreshImp() {
	// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpImp", "ButStoActive") == "true");

	// IP refreshImp.vars --- END

	// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVerImpexpImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshImp --- END
};

function refreshPpr() {
	// IP refreshPpr.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpPpr", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpPpr", "ButStoActive") == "true");

	// IP refreshPpr.vars --- END

	// IP refreshPpr --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmVerImpexpPpr", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshPpr --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexpLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmVerImpexpLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmVerImpexp", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerImpexp", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmVerImpexp" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
		} else if (shortDit == "Ppr") {
			refreshPpr();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Ppr

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmVerImpexpDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerImpexp", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmVerImpexp", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmVerImpexp", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerImpexpData", scrJref, "ContIacDlgWznmVerImpexp");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "ContIacDlgWznmVerImpexp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "ContInfDlgWznmVerImpexp", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "ContInfDlgWznmVerImpexpImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "ContInfDlgWznmVerImpexpLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "ContInfDlgWznmVerImpexpPpr", srcdoc)) mask.push("continfppr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatAppDlgWznmVerImpexp", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatShrDlgWznmVerImpexp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatShrDlgWznmVerImpexpIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatShrDlgWznmVerImpexpImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatShrDlgWznmVerImpexpLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "StatShrDlgWznmVerImpexpPpr", srcdoc)) mask.push("statshrppr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "TagDlgWznmVerImpexp", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "TagDlgWznmVerImpexpIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "TagDlgWznmVerImpexpImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "TagDlgWznmVerImpexpLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerImpexpData", "TagDlgWznmVerImpexpPpr", srcdoc)) mask.push("tagppr");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmVerImpexpData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmVerImpexpData") {
		handleDpchEngDlgWznmVerImpexpData(dom);
	};
};

function handleDpchEngDlgWznmVerImpexpData(dom) {
	// IP handleDpchEngDlgWznmVerImpexpData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVerImpexpData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVerImpexpData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
