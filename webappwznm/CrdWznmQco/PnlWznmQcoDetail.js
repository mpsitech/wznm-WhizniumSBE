// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmQcoDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmQcoDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmQcoDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmQcoDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmQcoDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSho", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptSho"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmQcoDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptQry", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptQry"));
	initCpt(contcontdoc, "CptTco", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptTco"));
	initCpt(contcontdoc, "CptStb", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptStb"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate");

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

	var height = 263; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "TxtSrfActive") == "true");

	var TxfShoActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "TxfShoActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "PupTypActive") == "true");

	var LstOccAlt = (retrieveSi(srcdoc, "StatAppWznmQcoDetail", "LstOccAlt") == "true");
	var LstOccActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "LstOccActive") == "true");

	var TxtQryActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "TxtQryActive") == "true");
	var ButQryViewAvail = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "ButQryViewAvail") == "true");
	var ButQryViewActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "ButQryViewActive") == "true");

	var TxtTcoActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "TxtTcoActive") == "true");

	var TxtStbActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "TxtStbActive") == "true");
	var ButStbViewAvail = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "ButStbViewAvail") == "true");
	var ButStbViewActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "ButStbViewActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmQcoDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmQcoDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfSho", "xs", retrieveCi(srcdoc, "ContIacWznmQcoDetail", "TxfSho"), TxfShoActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numFPupTyp");

	height -= setCtlAvail(contcontdoc, "Occ2", !LstOccAlt, 71);
	if ( (LstOccAlt == !contcontdoc.getElementById("ButOccExpand")) || (!LstOccAlt == !contcontdoc.getElementById("ButOccCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOcc");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOcc", retrieveTi(srcdoc, "TagWznmQcoDetail", "CptOcc")));

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
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOcc", "./PnlWznmQcoDetail_LstOcc.xml", false));
		};

	} else {
		if (!LstOccAlt) refreshLst(contcontdoc.getElementById("LstOcc").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOcc",
					parseInt(retrieveSi(srcdoc, "StatAppWznmQcoDetail", "LstOccNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numsFLstOcc")));
	};

	if (LstOccAlt) refreshTxt(contcontdoc, "TxtOcc", retrieveCi(srcdoc, "ContInfWznmQcoDetail", "TxtOcc"));

	if ((ButQryViewAvail == !contcontdoc.getElementById("ButQryView"))) {
		mytd = contcontdoc.getElementById("rdynQry");
		clearElem(mytd);

		first = true;

		if (ButQryViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButQryView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtQry", retrieveCi(srcdoc, "ContInfWznmQcoDetail", "TxtQry"));

	if (ButQryViewAvail) refreshButicon(contcontdoc, "ButQryView", "icon/view", ButQryViewActive, false);

	refreshTxt(contcontdoc, "TxtTco", retrieveCi(srcdoc, "ContInfWznmQcoDetail", "TxtTco"));

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

	refreshTxt(contcontdoc, "TxtStb", retrieveCi(srcdoc, "ContInfWznmQcoDetail", "TxtStb"));

	if (ButStbViewAvail) refreshButicon(contcontdoc, "ButStbView", "icon/view", ButStbViewActive, false);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmQcoDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmQcoDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmQcoDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmQcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmQcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmQcoDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmQcoDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmQcoDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmQcoDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmQcoDetailData", scrJref, "ContIacWznmQcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmQcoDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmQcoDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmQcoDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmQcoDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmQcoDetailData", scrJref, "ContIacWznmQcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmQcoDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmQcoDetailData", scrJref, "ContIacWznmQcoDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmQcoDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmQcoDetailData", scrJref, "ContIacWznmQcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "ContIacWznmQcoDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "ContInfWznmQcoDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "FeedFLstOcc", srcdoc)) mask.push("feedFLstOcc");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "StatAppWznmQcoDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "StatShrWznmQcoDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmQcoDetailData", "TagWznmQcoDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmQcoDetailData") {
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
			if (blk.nodeName == "DpchEngWznmQcoDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmQcoDetailData") {
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
