// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptBrt", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrDet", "CptBrt"));
	refreshRbu(contdoc, srcdoc, "RbuBrt", "FeedFDetRbuBrt", retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptrDet", "numFRbuBrt"), true);
	initCpt(contdoc, "CptGrl", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrDet", "CptGrl"));
	initBut(contdoc, "ButSta", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrDet", "ButSta"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone", "true");

	refreshDet();
};

function initIni() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIni --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrIni", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWznmRlsStareptrIni", "Uld");
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrIni", "CptPrg"));
	// IP initIni --- END

	setSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone", "true");

	refreshIni();
};

function initExt() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initExt --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrExt", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrExt", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrExt", "ButSto"));
	// IP initExt --- END

	setSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone", "true");

	refreshExt();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWznmRlsStareptrLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmRlsStareptr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmRlsStareptr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptr", "numFDse"));

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

function refreshDet() {
	// IP refreshDet.vars --- BEGIN

	var TxfGrlAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrDet", "TxfGrlAvail") == "true");

	var ButStaActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrDet", "ButStaActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	setRbuValue(contdoc, "RbuBrt", retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptrDet", "numFRbuBrt"), true);

	setCtlAvail(contdoc, "Grl", TxfGrlAvail, 25);
	if (TxfGrlAvail) {
		refreshTxf(contdoc, "TxfGrl", "", retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptrDet", "TxfGrl"), true, false, true);

	};

	refreshBut(contdoc, "ButSta", ButStaActive, false);

	// IP refreshDet --- END
};

function refreshIni() {
	// IP refreshIni.vars --- BEGIN
	var UldAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "UldAvail") == "true");
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "UldActive") == "true");

	var TxtPrgAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "TxtPrgAvail") == "true");

	var Sep1Avail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "Sep1Avail") == "true");

	var ButClgAvail = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "ButClgAvail") == "true");
	var ButClgActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrIni", "ButClgActive") == "true");

	var mytd, first;
	// IP refreshIni.vars --- END

	// IP refreshIni --- BEGIN
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

	setCtlAvail(contdoc, "Prg", TxtPrgAvail, 75);
	if (TxtPrgAvail) {
		refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmRlsStareptrIni", "TxtPrg"));

	};

	setCtlAvail(contdoc, "11", Sep1Avail, 0);
	setCtlAvail(contdoc, "12", Sep1Avail, 7);
	setCtlAvail(contdoc, "13", Sep1Avail, 0);
	if (Sep1Avail) {

	};

	setCtlAvail(contdoc, "Clg", ButClgAvail, 25);
	if (ButClgAvail) {
		if ((ButClgAvail == !contdoc.getElementById("ButClg"))) {
			mytd = contdoc.getElementById("dynClg");
			clearElem(mytd);

			first = true;

			if (ButClgAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "ButClg", retrieveTi(srcdoc, "TagDlgWznmRlsStareptrIni", "ButClg")));
			};
		};

		if (ButClgAvail) refreshBut(contdoc, "ButClg", ButClgActive, false);

	};

	// IP refreshIni --- END
};

function refreshExt() {
	// IP refreshExt.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrExt", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrExt", "ButStoActive") == "true");

	// IP refreshExt.vars --- END

	// IP refreshExt --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWznmRlsStareptrExt", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshExt --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptrLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmRlsStareptrLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWznmRlsStareptr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWznmRlsStareptr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Ini") {
			refreshIni();
		} else if (shortDit == "Ext") {
			refreshExt();
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

// --- specific event handlers for app controls of dialog item Det

// --- specific event handlers for app controls of dialog item Ini

// --- specific event handlers for app controls of dialog item Ext

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWznmRlsStareptrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmRlsStareptr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWznmRlsStareptr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWznmRlsStareptr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsStareptrData", scrJref, "ContIacDlgWznmRlsStareptr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleRbuSelect(_doc, ditshort, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgWznmRlsStareptr" + ditshort, "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsStareptrData", scrJref, "ContIacDlgWznmRlsStareptr" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWznmRlsStareptr" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsStareptrData", scrJref, "ContIacDlgWznmRlsStareptr" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWznmRlsStareptr" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmRlsStareptrData", scrJref, "ContIacDlgWznmRlsStareptr" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContIacDlgWznmRlsStareptr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContIacDlgWznmRlsStareptrDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContInfDlgWznmRlsStareptr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContInfDlgWznmRlsStareptrExt", srcdoc)) mask.push("continfext");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContInfDlgWznmRlsStareptrIni", srcdoc)) mask.push("continfini");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "ContInfDlgWznmRlsStareptrLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "FeedFDetRbuBrt", srcdoc)) mask.push("feedFDetRbuBrt");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatAppDlgWznmRlsStareptr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatShrDlgWznmRlsStareptr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatShrDlgWznmRlsStareptrDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatShrDlgWznmRlsStareptrExt", srcdoc)) mask.push("statshrext");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatShrDlgWznmRlsStareptrIni", srcdoc)) mask.push("statshrini");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "StatShrDlgWznmRlsStareptrLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "TagDlgWznmRlsStareptr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "TagDlgWznmRlsStareptrDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "TagDlgWznmRlsStareptrExt", srcdoc)) mask.push("tagext");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "TagDlgWznmRlsStareptrIni", srcdoc)) mask.push("tagini");
	if (updateSrcblock(dom, "DpchEngDlgWznmRlsStareptrData", "TagDlgWznmRlsStareptrLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWznmRlsStareptrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWznmRlsStareptrData") {
		handleDpchEngDlgWznmRlsStareptrData(dom);
	};
};

function handleDpchEngDlgWznmRlsStareptrData(dom) {
	// IP handleDpchEngDlgWznmRlsStareptrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmRlsStareptrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmRlsStareptrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

