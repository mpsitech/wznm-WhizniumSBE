// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptFnm", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptFnm"));
	initCpt(contdoc, "CptRet", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptRet"));
	refreshPup(contdoc, srcdoc, "PupRet", "", "FeedFDetPupRet", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "numFPupRet"), true, false);
	initCpt(contdoc, "CptReu", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptReu"));
	initCpt(contdoc, "CptCnt", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptCnt"));
	initCpt(contdoc, "CptMim", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptMim"));
	initCpt(contdoc, "CptCmt", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "CptCmt"));
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgWznmFilNewDet", "ButCre"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWznmFilNew", "initdone", "true");

	refreshDet();
};

function initFil() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFil --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmFilNewFil", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmFilNewFil", "Uld");
	// IP initFil --- END

	setSi(srcdoc, "StatAppDlgWznmFilNew", "initdone", "true");

	refreshFil();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmFilNew", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmFilNew", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmFilNew", "numFDse"));

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

function refreshDet() {
	// IP refreshDet.vars --- BEGIN

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWznmFilNewDet", "ButCreActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	refreshTxf(contdoc, "TxfFnm", "", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "TxfFnm"), true, false, true);

	contdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "numFPupRet");

	refreshTxf(contdoc, "TxfReu", "", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "TxfReu"), true, false, true);

	refreshPup(contdoc, srcdoc, "PupCnt", "", "FeedFDetPupCnt", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "numFPupCnt"), true, false);

	refreshPup(contdoc, srcdoc, "PupMim", "", "FeedFDetPupMim", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "numFPupMim"), true, false);

	refreshTxft(contdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacDlgWznmFilNewDet", "TxfCmt"), true, false, true);

	refreshBut(contdoc, "ButCre", ButCreActive, false);

	// IP refreshDet --- END
};

function refreshFil() {
	// IP refreshFil.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmFilNewFil", "UldActive") == "true");

	// IP refreshFil.vars --- END

	// IP refreshFil --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshFil --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmFilNew", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmFilNew", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmFilNew", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmFilNew" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Fil") {
			refreshFil();
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

// --- specific event handlers for app controls of dialog item Fil

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmFilNewDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmFilNew", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmFilNew", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmFilNew", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmFilNewData", scrJref, "ContIacDlgWznmFilNew");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmFilNew" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmFilNewData", scrJref, "ContIacDlgWznmFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWznmFilNew" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmFilNewData", scrJref, "ContIacDlgWznmFilNew" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWznmFilNew" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmFilNewData", scrJref, "ContIacDlgWznmFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ditshort, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacDlgWznmFilNew" + ditshort, ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmFilNewData", scrJref, "ContIacDlgWznmFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "ContIacDlgWznmFilNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "ContIacDlgWznmFilNewDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "ContInfDlgWznmFilNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "FeedFDetPupCnt", srcdoc)) mask.push("feedFDetPupCnt");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "FeedFDetPupMim", srcdoc)) mask.push("feedFDetPupMim");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "FeedFDetPupRet", srcdoc)) mask.push("feedFDetPupRet");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "StatAppDlgWznmFilNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "StatShrDlgWznmFilNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "StatShrDlgWznmFilNewDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "StatShrDlgWznmFilNewFil", srcdoc)) mask.push("statshrfil");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "TagDlgWznmFilNew", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "TagDlgWznmFilNewDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmFilNewData", "TagDlgWznmFilNewFil", srcdoc)) mask.push("tagfil");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmFilNewData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmFilNewData") {
		handleDpchEngDlgWznmFilNewData(dom);
	};
};

function handleDpchEngDlgWznmFilNewData(dom) {
	// IP handleDpchEngDlgWznmFilNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmFilNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmFilNewData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

