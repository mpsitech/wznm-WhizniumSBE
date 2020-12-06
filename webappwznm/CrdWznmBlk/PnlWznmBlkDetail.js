// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmBlkDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmBlkDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmBlkDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmBlkDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmBlkDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmBlkDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptVer"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate");

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

	var height = 384; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "TxtSrfActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "PupTypActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "ButVerViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "ButReuViewActive") == "true");

	var LstReaAlt = (retrieveSi(srcdoc, "StatAppWznmBlkDetail", "LstReaAlt") == "true");
	var LstReaActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "LstReaActive") == "true");

	var LstWriAlt = (retrieveSi(srcdoc, "StatAppWznmBlkDetail", "LstWriAlt") == "true");
	var LstWriActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "LstWriActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmBlkDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmBlkDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numFPupTyp");

	if ((ButVerViewAvail == !contcontdoc.getElementById("ButVerView"))) {
		mytd = contcontdoc.getElementById("rdynVer");
		clearElem(mytd);

		first = true;

		if (ButVerViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVerView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmBlkDetail", "TxtVer"));

	if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmBlkDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	height -= setCtlAvail(contcontdoc, "Rea2", !LstReaAlt, 71);
	if ( (LstReaAlt == !contcontdoc.getElementById("ButReaExpand")) || (!LstReaAlt == !contcontdoc.getElementById("ButReaCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynRea");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptRea", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptRea")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstReaAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButReaExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButReaCollapse", "icon/collapse"));
	};

	if ( (LstReaAlt == !contcontdoc.getElementById("TxtRea")) || (!LstReaAlt == !contcontdoc.getElementById("LstRea")) ) {
		mytd = contcontdoc.getElementById("dynRea");
		clearElem(mytd);

		if (LstReaAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtRea", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstRea", "./PnlWznmBlkDetail_LstRea.xml", false));
		};

	} else {
		if (!LstReaAlt) refreshLst(contcontdoc.getElementById("LstRea").contentWindow.document, srcdoc, 1, false, true, "FeedFLstRea",
					parseInt(retrieveSi(srcdoc, "StatAppWznmBlkDetail", "LstReaNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numsFLstRea")));
	};

	if (LstReaAlt) refreshTxt(contcontdoc, "TxtRea", retrieveCi(srcdoc, "ContInfWznmBlkDetail", "TxtRea"));

	height -= setCtlAvail(contcontdoc, "Wri2", !LstWriAlt, 71);
	if ( (LstWriAlt == !contcontdoc.getElementById("ButWriExpand")) || (!LstWriAlt == !contcontdoc.getElementById("ButWriCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynWri");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptWri", retrieveTi(srcdoc, "TagWznmBlkDetail", "CptWri")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstWriAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButWriExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButWriCollapse", "icon/collapse"));
	};

	if ( (LstWriAlt == !contcontdoc.getElementById("TxtWri")) || (!LstWriAlt == !contcontdoc.getElementById("LstWri")) ) {
		mytd = contcontdoc.getElementById("dynWri");
		clearElem(mytd);

		if (LstWriAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtWri", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstWri", "./PnlWznmBlkDetail_LstWri.xml", false));
		};

	} else {
		if (!LstWriAlt) refreshLst(contcontdoc.getElementById("LstWri").contentWindow.document, srcdoc, 1, false, true, "FeedFLstWri",
					parseInt(retrieveSi(srcdoc, "StatAppWznmBlkDetail", "LstWriNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numsFLstWri")));
	};

	if (LstWriAlt) refreshTxt(contcontdoc, "TxtWri", retrieveCi(srcdoc, "ContInfWznmBlkDetail", "TxtWri"));

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmBlkDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmBlkDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmBlkDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmBlkDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmBlkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmBlkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmBlkDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmBlkDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmBlkDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmBlkDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmBlkDetailData", scrJref, "ContIacWznmBlkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmBlkDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmBlkDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmBlkDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmBlkDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmBlkDetailData", scrJref, "ContIacWznmBlkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWznmBlkDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmBlkDetailData", scrJref, "ContIacWznmBlkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "ContIacWznmBlkDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "ContInfWznmBlkDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "FeedFLstRea", srcdoc)) mask.push("feedFLstRea");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "FeedFLstWri", srcdoc)) mask.push("feedFLstWri");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "StatAppWznmBlkDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "StatShrWznmBlkDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmBlkDetailData", "TagWznmBlkDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmBlkDetailData") {
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
			if (blk.nodeName == "DpchEngWznmBlkDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmBlkDetailData") {
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
