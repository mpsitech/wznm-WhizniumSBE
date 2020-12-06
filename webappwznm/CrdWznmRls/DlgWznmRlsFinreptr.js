// IP cust --- INSERT

// --- view initialization and refresh
function initFin() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFin --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrFin", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrFin", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrFin", "ButSto"));
	// IP initFin --- END

	setSi(srcdoc, "StatAppDlgWznmRlsFinreptr", "initdone", "true");

	refreshFin();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrRes", "Dld"));
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrRes", "CptPrg"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWznmRlsFinreptr", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmRlsFinreptr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmRlsFinreptr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsFinreptr", "numFDse"));

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

function refreshFin() {
	// IP refreshFin.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrFin", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrFin", "ButStoActive") == "true");

	// IP refreshFin.vars --- END

	// IP refreshFin --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmRlsFinreptrFin", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshFin --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "DldAvail") == "true");
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "DldActive") == "true");

	var TxtPrgAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "TxtPrgAvail") == "true");

	var Sep1Avail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "Sep1Avail") == "true");

	var ButPsgAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "ButPsgAvail") == "true");
	var ButPsgActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptrRes", "ButPsgActive") == "true");

	var mytd, first;
	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	setCtlAvail(contdoc, "", DldAvail, 25);
	if (DldAvail) {
		refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmRlsFinreptrRes", "Dld"), DldActive);

	};

	setCtlAvail(contdoc, "Prg", TxtPrgAvail, 75);
	if (TxtPrgAvail) {
		refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmRlsFinreptrRes", "TxtPrg"));

	};

	setCtlAvail(contdoc, "11", Sep1Avail, 0);
	setCtlAvail(contdoc, "12", Sep1Avail, 7);
	setCtlAvail(contdoc, "13", Sep1Avail, 0);
	if (Sep1Avail) {

	};

	setCtlAvail(contdoc, "Psg", ButPsgAvail, 25);
	if (ButPsgAvail) {
		if ((ButPsgAvail == !contdoc.getElementById("ButPsg"))) {
			mytd = contdoc.getElementById("dynPsg");
			clearElem(mytd);

			first = true;

			if (ButPsgAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "ButPsg", retrieveTi(srcdoc, "TagDlgWznmRlsFinreptrRes", "ButPsg")));
			};
		};

		if (ButPsgAvail) refreshBut(contdoc, "ButPsg", ButPsgActive, false);

	};

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmRlsFinreptr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmRlsFinreptr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsFinreptr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmRlsFinreptr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Fin") {
			refreshFin();
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

// --- specific event handlers for app controls of dialog item Fin

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmRlsFinreptrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsFinreptr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmRlsFinreptr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmRlsFinreptr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsFinreptrData", scrJref, "ContIacDlgWznmRlsFinreptr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "ContIacDlgWznmRlsFinreptr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "ContInfDlgWznmRlsFinreptr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "ContInfDlgWznmRlsFinreptrFin", srcdoc)) mask.push("continffin");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "ContInfDlgWznmRlsFinreptrRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "StatAppDlgWznmRlsFinreptr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "StatShrDlgWznmRlsFinreptr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "StatShrDlgWznmRlsFinreptrFin", srcdoc)) mask.push("statshrfin");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "StatShrDlgWznmRlsFinreptrRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "TagDlgWznmRlsFinreptr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "TagDlgWznmRlsFinreptrFin", srcdoc)) mask.push("tagfin");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsFinreptrData", "TagDlgWznmRlsFinreptrRes", srcdoc)) mask.push("tagres");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmRlsFinreptrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmRlsFinreptrData") {
		handleDpchEngDlgWznmRlsFinreptrData(dom);
	};
};

function handleDpchEngDlgWznmRlsFinreptrData(dom) {
	// IP handleDpchEngDlgWznmRlsFinreptrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmRlsFinreptrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmRlsFinreptrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
