// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptBso", retrieveTi(srcdoc, "TagDlgWznmRlsWriteDet", "CptBso"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "true");

	refreshDet();
};

function initCuc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCuc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmRlsWriteCuc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmRlsWriteCuc", "Uld");
	// IP initCuc --- END

	setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "true");

	refreshCuc();
};

function initWrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWrc --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmRlsWriteWrc", "CptPrg"));
	initBut(contdoc, "ButAut", retrieveTi(srcdoc, "TagDlgWznmRlsWriteWrc", "ButAut"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmRlsWriteWrc", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmRlsWriteWrc", "ButSto"));
	// IP initWrc --- END

	setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "true");

	refreshWrc();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmRlsWriteLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "true");

	refreshLfi();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmRlsWriteFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmRlsWrite", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmRlsWrite", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsWrite", "numFDse"));

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

function refreshDet() {
	// IP refreshDet.vars --- BEGIN

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	refreshChk(contdoc, "ChkBso", (retrieveCi(srcdoc, "ContIacDlgWznmRlsWriteDet", "ChkBso") == "true"), true);

	// IP refreshDet --- END
};

function refreshCuc() {
	// IP refreshCuc.vars --- BEGIN
	var UldAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteCuc", "UldAvail") == "true");
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteCuc", "UldActive") == "true");

	// IP refreshCuc.vars --- END

	// IP refreshCuc --- BEGIN
	setCtlAvail(contdoc, "", UldAvail, 25);
	if (UldAvail) {

		if (UldActive) {
			contdoc.getElementById("But").setAttribute("class", "but");
			contdoc.getElementById("But").setAttribute("type", "submit");
		} else {
			contdoc.getElementById("But").setAttribute("class", "butinact");
			contdoc.getElementById("But").setAttribute("type", "reset");
		};

	};

	// IP refreshCuc --- END
};

function refreshWrc() {
	// IP refreshWrc.vars --- BEGIN

	var ButAutActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteWrc", "ButAutActive") == "true");

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteWrc", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteWrc", "ButStoActive") == "true");

	// IP refreshWrc.vars --- END

	// IP refreshWrc --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmRlsWriteWrc", "TxtPrg"));

	refreshBut(contdoc, "ButAut", ButAutActive, false);

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWrc --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmRlsWriteLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteFia", "DldAvail") == "true");
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWriteFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	setCtlAvail(contdoc, "", DldAvail, 25);
	if (DldAvail) {
		refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmRlsWriteFia", "Dld"), DldActive);

	};

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmRlsWrite", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsWrite", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmRlsWrite" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Cuc") {
			refreshCuc();
		} else if (shortDit == "Wrc") {
			refreshWrc();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Det

// --- specific event handlers for app controls of dialog item Cuc

// --- specific event handlers for app controls of dialog item Wrc

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmRlsWriteDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgWznmRlsWrite" + ditshort, ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsWriteData", scrJref, "ContIacDlgWznmRlsWrite" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsWrite", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmRlsWrite", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmRlsWrite", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsWriteData", scrJref, "ContIacDlgWznmRlsWrite");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContIacDlgWznmRlsWrite", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContIacDlgWznmRlsWriteDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContInfDlgWznmRlsWrite", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContInfDlgWznmRlsWriteFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContInfDlgWznmRlsWriteLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "ContInfDlgWznmRlsWriteWrc", srcdoc)) mask.push("continfwrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatAppDlgWznmRlsWrite", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatShrDlgWznmRlsWrite", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatShrDlgWznmRlsWriteCuc", srcdoc)) mask.push("statshrcuc");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatShrDlgWznmRlsWriteFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatShrDlgWznmRlsWriteLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "StatShrDlgWznmRlsWriteWrc", srcdoc)) mask.push("statshrwrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWrite", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWriteCuc", srcdoc)) mask.push("tagcuc");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWriteDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWriteFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWriteLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsWriteData", "TagDlgWznmRlsWriteWrc", srcdoc)) mask.push("tagwrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmRlsWriteData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmRlsWriteData") {
		handleDpchEngDlgWznmRlsWriteData(dom);
	};
};

function handleDpchEngDlgWznmRlsWriteData(dom) {
	// IP handleDpchEngDlgWznmRlsWriteData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmRlsWriteData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmRlsWriteData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

