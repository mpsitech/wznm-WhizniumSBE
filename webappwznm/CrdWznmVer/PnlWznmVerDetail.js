/**
  * \file PnlWznmVerDetail.js
  * web client functionality for panel PnlWznmVerDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmVerDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVerDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmVerDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVerDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmVerDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagWznmVerDetail", "CptPrj"));
	initCpt(contcontdoc, "CptMaj", retrieveTi(srcdoc, "TagWznmVerDetail", "CptMaj"));
	initCpt(contcontdoc, "CptMin", retrieveTi(srcdoc, "TagWznmVerDetail", "CptMin"));
	initCpt(contcontdoc, "CptSub", retrieveTi(srcdoc, "TagWznmVerDetail", "CptSub"));
	initCpt(contcontdoc, "CptBvr", retrieveTi(srcdoc, "TagWznmVerDetail", "CptBvr"));
	initCpt(contcontdoc, "CptLoc", retrieveTi(srcdoc, "TagWznmVerDetail", "CptLoc"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWznmVerDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacWznmVerDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrWznmVerDetail", "PupSteActive"), false);
	initCpt(contcontdoc, "CptAb1", retrieveTi(srcdoc, "TagWznmVerDetail", "CptAb1"));
	initCpt(contcontdoc, "CptAb2", retrieveTi(srcdoc, "TagWznmVerDetail", "CptAb2"));
	initCpt(contcontdoc, "CptAb3", retrieveTi(srcdoc, "TagWznmVerDetail", "CptAb3"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmVerDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate");

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

	var height = 734; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrjActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtPrjActive") == "true");
	var ButPrjViewAvail = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButPrjViewAvail") == "true");
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButPrjViewActive") == "true");

	var TxfMajActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxfMajActive") == "true");

	var TxfMinActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxfMinActive") == "true");

	var TxfSubActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxfSubActive") == "true");

	var TxtBvrActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtBvrActive") == "true");
	var ButBvrViewAvail = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButBvrViewAvail") == "true");
	var ButBvrViewActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButBvrViewActive") == "true");

	var TxtLocActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtLocActive") == "true");
	var ButLocViewAvail = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButLocViewAvail") == "true");
	var ButLocViewActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButLocViewActive") == "true");

	var PupJstActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "PupJstActive") == "true");
	var ButJstEditAvail = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButJstEditAvail") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "PupSteActive") == "true");

	var LstDtyAlt = (retrieveSi(srcdoc, "StatAppWznmVerDetail", "LstDtyAlt") == "true");
	var LstDtyActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "LstDtyActive") == "true");

	var LstOptAlt = (retrieveSi(srcdoc, "StatAppWznmVerDetail", "LstOptAlt") == "true");
	var LstOptActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "LstOptActive") == "true");

	var PupJActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "PupJActive") == "true");
	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButJEditAvail") == "true");

	var TxtAb1Active = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtAb1Active") == "true");

	var TxtAb2Active = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtAb2Active") == "true");

	var TxtAb3Active = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxtAb3Active") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmVerDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView"))) {
		mytd = contcontdoc.getElementById("rdynPrj");
		clearElem(mytd);

		first = true;

		if (ButPrjViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrj", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtPrj"));

	if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	refreshTxf(contcontdoc, "TxfMaj", "s", retrieveCi(srcdoc, "ContIacWznmVerDetail", "TxfMaj"), TxfMajActive, false, true);

	refreshTxf(contcontdoc, "TxfMin", "s", retrieveCi(srcdoc, "ContIacWznmVerDetail", "TxfMin"), TxfMinActive, false, true);

	refreshTxf(contcontdoc, "TxfSub", "s", retrieveCi(srcdoc, "ContIacWznmVerDetail", "TxfSub"), TxfSubActive, false, true);

	if ((ButBvrViewAvail == !contcontdoc.getElementById("ButBvrView"))) {
		mytd = contcontdoc.getElementById("rdynBvr");
		clearElem(mytd);

		first = true;

		if (ButBvrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBvrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtBvr", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtBvr"));

	if (ButBvrViewAvail) refreshButicon(contcontdoc, "ButBvrView", "icon/view", ButBvrViewActive, false);

	if ((ButLocViewAvail == !contcontdoc.getElementById("ButLocView"))) {
		mytd = contcontdoc.getElementById("rdynLoc");
		clearElem(mytd);

		first = true;

		if (ButLocViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLocView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtLoc", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtLoc"));

	if (ButLocViewAvail) refreshButicon(contcontdoc, "ButLocView", "icon/view", ButLocViewActive, false);

	if ((ButJstEditAvail == !contcontdoc.getElementById("ButJstEdit"))) {
		mytd = contcontdoc.getElementById("rdynJst");
		clearElem(mytd);

		first = true;

		if (ButJstEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJstEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJst", "s", "FeedFPupJst", retrieveCi(srcdoc, "ContIacWznmVerDetail", "numFPupJst"), PupJstActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacWznmVerDetail", "numFPupSte");

	height -= setCtlAvail(contcontdoc, "Dty2", !LstDtyAlt, 71);
	if ( (LstDtyAlt == !contcontdoc.getElementById("ButDtyExpand")) || (!LstDtyAlt == !contcontdoc.getElementById("ButDtyCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynDty");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptDty", retrieveTi(srcdoc, "TagWznmVerDetail", "CptDty")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstDtyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDtyExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButDtyCollapse", "icon/collapse"));
	};

	if ( (LstDtyAlt == !contcontdoc.getElementById("TxtDty")) || (!LstDtyAlt == !contcontdoc.getElementById("LstDty")) ) {
		mytd = contcontdoc.getElementById("dynDty");
		clearElem(mytd);

		if (LstDtyAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtDty", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstDty", "./PnlWznmVerDetail_LstDty.xml", false));
		};

	} else {
		if (!LstDtyAlt) refreshLst(contcontdoc.getElementById("LstDty").contentWindow.document, srcdoc, 1, false, true, "FeedFLstDty",
					parseInt(retrieveSi(srcdoc, "StatAppWznmVerDetail", "LstDtyNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numsFLstDty")));
	};

	if (LstDtyAlt) refreshTxt(contcontdoc, "TxtDty", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtDty"));

	height -= setCtlAvail(contcontdoc, "Opt2", !LstOptAlt, 71);
	if ( (LstOptAlt == !contcontdoc.getElementById("ButOptExpand")) || (!LstOptAlt == !contcontdoc.getElementById("ButOptCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOpt");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpt", retrieveTi(srcdoc, "TagWznmVerDetail", "CptOpt")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstOptAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOptExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButOptCollapse", "icon/collapse"));
	};

	if ( (LstOptAlt == !contcontdoc.getElementById("TxtOpt")) || (!LstOptAlt == !contcontdoc.getElementById("LstOpt")) ) {
		mytd = contcontdoc.getElementById("dynOpt");
		clearElem(mytd);

		if (LstOptAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtOpt", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOpt", "./PnlWznmVerDetail_LstOpt.xml", false));
		};

	} else {
		if (!LstOptAlt) refreshLst(contcontdoc.getElementById("LstOpt").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOpt",
					parseInt(retrieveSi(srcdoc, "StatAppWznmVerDetail", "LstOptNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numsFLstOpt")));
	};

	if (LstOptAlt) refreshTxt(contcontdoc, "TxtOpt", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtOpt"));

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacWznmVerDetail", "numFPupJ"), PupJActive, false);

	refreshTxtt(contcontdoc, "TxtAb1", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtAb1"));

	refreshTxtt(contcontdoc, "TxtAb2", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtAb2"));

	refreshTxtt(contcontdoc, "TxtAb3", retrieveCi(srcdoc, "ContInfWznmVerDetail", "TxtAb3"));

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmVerDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVerDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmVerDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmVerDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmVerDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmVerDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmVerDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmVerDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVerDetailData", scrJref, "ContIacWznmVerDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmVerDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmVerDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmVerDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmVerDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVerDetailData", scrJref, "ContIacWznmVerDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmVerDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmVerDetailData", scrJref, "ContIacWznmVerDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmVerDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVerDetailData", scrJref, "ContIacWznmVerDetail");
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

	setCi(srcdoc, "ContIacWznmVerDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVerDetailData", scrJref, "ContIacWznmVerDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "ContIacWznmVerDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "ContInfWznmVerDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "FeedFLstDty", srcdoc)) mask.push("feedFLstDty");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "FeedFLstOpt", srcdoc)) mask.push("feedFLstOpt");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "FeedFPupJst", srcdoc)) mask.push("feedFPupJst");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "StatAppWznmVerDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "StatShrWznmVerDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVerDetailData", "TagWznmVerDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmVerDetailData") {
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
			if (blk.nodeName == "DpchEngWznmVerDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmVerDetailData") {
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

function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

