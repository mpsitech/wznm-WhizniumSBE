// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmIelDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmIelDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmIelDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmIelDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmIelDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmIelDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSho", retrieveTi(srcdoc, "TagWznmIelDetail", "CptSho"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmIelDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmIelDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmIelDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptIme", retrieveTi(srcdoc, "TagWznmIelDetail", "CptIme"));
	initCpt(contcontdoc, "CptTco", retrieveTi(srcdoc, "TagWznmIelDetail", "CptTco"));
	initCpt(contcontdoc, "CptIm2", retrieveTi(srcdoc, "TagWznmIelDetail", "CptIm2"));
	initCpt(contcontdoc, "CptCty", retrieveTi(srcdoc, "TagWznmIelDetail", "CptCty"));
	refreshPup(contcontdoc, srcdoc, "PupCty", "", "FeedFPupCty", retrieveCi(srcdoc, "ContIacWznmIelDetail", "numFPupCty"), retrieveSi(srcdoc, "StatShrWznmIelDetail", "PupCtyActive"), false);
	initCpt(contcontdoc, "CptDfv", retrieveTi(srcdoc, "TagWznmIelDetail", "CptDfv"));
	initCpt(contcontdoc, "CptPst", retrieveTi(srcdoc, "TagWznmIelDetail", "CptPst"));
	initCpt(contcontdoc, "CptStb", retrieveTi(srcdoc, "TagWznmIelDetail", "CptStb"));
	initCpt(contcontdoc, "CptVit", retrieveTi(srcdoc, "TagWznmIelDetail", "CptVit"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		initA();
	} else if (srefIxWznmVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 388; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtSrfActive") == "true");

	var TxfShoActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxfShoActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "PupTypActive") == "true");

	var LstOccAlt = (retrieveSi(srcdoc, "StatAppWznmIelDetail", "LstOccAlt") == "true");
	var LstOccActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "LstOccActive") == "true");

	var TxtImeActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtImeActive") == "true");
	var ButImeViewAvail = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButImeViewAvail") == "true");
	var ButImeViewActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButImeViewActive") == "true");

	var TxtTcoActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtTcoActive") == "true");

	var TxtIm2Active = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtIm2Active") == "true");
	var ButIm2ViewAvail = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButIm2ViewAvail") == "true");
	var ButIm2ViewActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButIm2ViewActive") == "true");

	var PupCtyActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "PupCtyActive") == "true");

	var TxfDfvActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxfDfvActive") == "true");

	var TxtPstActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtPstActive") == "true");
	var ButPstViewAvail = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButPstViewAvail") == "true");
	var ButPstViewActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButPstViewActive") == "true");

	var TxtStbActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtStbActive") == "true");
	var ButStbViewAvail = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButStbViewAvail") == "true");
	var ButStbViewActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButStbViewActive") == "true");

	var TxtVitActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "TxtVitActive") == "true");
	var ButVitViewAvail = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButVitViewAvail") == "true");
	var ButVitViewActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButVitViewActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmIelDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfSho", "xs", retrieveCi(srcdoc, "ContIacWznmIelDetail", "TxfSho"), TxfShoActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmIelDetail", "numFPupTyp");

	height -= setCtlAvail(contcontdoc, "Occ2", !LstOccAlt, 71);
	if ( (LstOccAlt == !contcontdoc.getElementById("ButOccExpand")) || (!LstOccAlt == !contcontdoc.getElementById("ButOccCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOcc");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOcc", retrieveTi(srcdoc, "TagWznmIelDetail", "CptOcc")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstOccAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOccExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButOccCollapse", "icon/collapse"));
	};

	if ( (LstOccAlt == !contcontdoc.getElementById("TxtOcc")) || (!LstOccAlt == !contcontdoc.getElementById("LstOcc")) ) {
		mytd = contcontdoc.getElementById("dynOcc");
		clearElem(mytd);

		if (LstOccAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtOcc", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOcc", "./PnlWznmIelDetail_LstOcc.xml", false));
		};

	} else {
		if (!LstOccAlt) refreshLst(contcontdoc.getElementById("LstOcc").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOcc",
					parseInt(retrieveSi(srcdoc, "StatAppWznmIelDetail", "LstOccNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numsFLstOcc")));
	};

	if (LstOccAlt) refreshTxt(contcontdoc, "TxtOcc", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtOcc"));

	if ((ButImeViewAvail == !contcontdoc.getElementById("ButImeView"))) {
		mytd = contcontdoc.getElementById("rdynIme");
		clearElem(mytd);

		first = true;

		if (ButImeViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButImeView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtIme", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtIme"));

	if (ButImeViewAvail) refreshButicon(contcontdoc, "ButImeView", "icon/view", ButImeViewActive, false);

	refreshTxt(contcontdoc, "TxtTco", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtTco"));

	if ((ButIm2ViewAvail == !contcontdoc.getElementById("ButIm2View"))) {
		mytd = contcontdoc.getElementById("rdynIm2");
		clearElem(mytd);

		first = true;

		if (ButIm2ViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButIm2View", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtIm2", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtIm2"));

	if (ButIm2ViewAvail) refreshButicon(contcontdoc, "ButIm2View", "icon/view", ButIm2ViewActive, false);

	contcontdoc.getElementById("PupCty").value = retrieveCi(srcdoc, "ContIacWznmIelDetail", "numFPupCty");

	refreshTxf(contcontdoc, "TxfDfv", "", retrieveCi(srcdoc, "ContIacWznmIelDetail", "TxfDfv"), TxfDfvActive, false, true);

	if ((ButPstViewAvail == !contcontdoc.getElementById("ButPstView"))) {
		mytd = contcontdoc.getElementById("rdynPst");
		clearElem(mytd);

		first = true;

		if (ButPstViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPst", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtPst"));

	if (ButPstViewAvail) refreshButicon(contcontdoc, "ButPstView", "icon/view", ButPstViewActive, false);

	if ((ButStbViewAvail == !contcontdoc.getElementById("ButStbView"))) {
		mytd = contcontdoc.getElementById("rdynStb");
		clearElem(mytd);

		first = true;

		if (ButStbViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButStbView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtStb", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtStb"));

	if (ButStbViewAvail) refreshButicon(contcontdoc, "ButStbView", "icon/view", ButStbViewActive, false);

	if ((ButVitViewAvail == !contcontdoc.getElementById("ButVitView"))) {
		mytd = contcontdoc.getElementById("rdynVit");
		clearElem(mytd);

		first = true;

		if (ButVitViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVitView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtVit", retrieveCi(srcdoc, "ContInfWznmIelDetail", "TxtVit"));

	if (ButVitViewAvail) refreshButicon(contcontdoc, "ButVitView", "icon/view", ButVitViewActive, false);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmIelDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		refreshA();
	} else if (srefIxWznmVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmIelDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmIelDetail", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmIelDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmIelDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmIelDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmIelDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWznmIelDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmIelDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmIelDetailData", scrJref, "ContIacWznmIelDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmIelDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmIelDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmIelDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmIelDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmIelDetailData", scrJref, "ContIacWznmIelDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmIelDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmIelDetailData", scrJref, "ContIacWznmIelDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmIelDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmIelDetailData", scrJref, "ContIacWznmIelDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "ContIacWznmIelDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "ContInfWznmIelDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "FeedFLstOcc", srcdoc)) mask.push("feedFLstOcc");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "FeedFPupCty", srcdoc)) mask.push("feedFPupCty");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "StatAppWznmIelDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "StatShrWznmIelDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmIelDetailData", "TagWznmIelDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmIelDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWznmIelDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWznmIelDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");
				_scrJref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:scrJref");
				sref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWznmAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));
			};
		};
	};
};
