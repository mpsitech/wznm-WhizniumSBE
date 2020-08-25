/**
  * \file DlgWznmAppWrite.js
  * web client functionality for dialog DlgWznmAppWrite
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptUsf", retrieveTi(srcdoc, "TagDlgWznmAppWriteDet", "CptUsf"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "true");

	refreshDet();
};

function initCuc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCuc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmAppWriteCuc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmAppWriteCuc", "Uld");
	// IP initCuc --- END

	setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "true");

	refreshCuc();
};

function initWrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWrc --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmAppWriteWrc", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmAppWriteWrc", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmAppWriteWrc", "ButSto"));
	// IP initWrc --- END

	setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "true");

	refreshWrc();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmAppWriteLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "true");

	refreshLfi();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmAppWriteFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmAppWrite", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmAppWrite", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmAppWrite", "numFDse"));

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
	refreshChk(contdoc, "ChkUsf", (retrieveCi(srcdoc, "ContIacDlgWznmAppWriteDet", "ChkUsf") == "true"), true);

	// IP refreshDet --- END
};

function refreshCuc() {
	// IP refreshCuc.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWriteCuc", "UldActive") == "true");

	// IP refreshCuc.vars --- END

	// IP refreshCuc --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshCuc --- END
};

function refreshWrc() {
	// IP refreshWrc.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWriteWrc", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWriteWrc", "ButStoActive") == "true");

	// IP refreshWrc.vars --- END

	// IP refreshWrc --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmAppWriteWrc", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWrc --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWriteLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmAppWriteLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWriteFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmAppWriteFia", "Dld"), DldActive);

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmAppWrite", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmAppWrite", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmAppWrite" + shortDit + ".xml" 

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
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmAppWriteDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgWznmAppWrite" + ditshort, ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmAppWriteData", scrJref, "ContIacDlgWznmAppWrite" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmAppWrite", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmAppWrite", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmAppWrite", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmAppWriteData", scrJref, "ContIacDlgWznmAppWrite");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContIacDlgWznmAppWrite", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContIacDlgWznmAppWriteDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContInfDlgWznmAppWrite", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContInfDlgWznmAppWriteFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContInfDlgWznmAppWriteLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "ContInfDlgWznmAppWriteWrc", srcdoc)) mask.push("continfwrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatAppDlgWznmAppWrite", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatShrDlgWznmAppWrite", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatShrDlgWznmAppWriteCuc", srcdoc)) mask.push("statshrcuc");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatShrDlgWznmAppWriteFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatShrDlgWznmAppWriteLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "StatShrDlgWznmAppWriteWrc", srcdoc)) mask.push("statshrwrc");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWrite", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWriteCuc", srcdoc)) mask.push("tagcuc");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWriteDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWriteFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWriteLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmAppWriteData", "TagDlgWznmAppWriteWrc", srcdoc)) mask.push("tagwrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmAppWriteData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmAppWriteData") {
		handleDpchEngDlgWznmAppWriteData(dom);
	};
};

function handleDpchEngDlgWznmAppWriteData(dom) {
	// IP handleDpchEngDlgWznmAppWriteData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmAppWriteData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmAppWriteData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

