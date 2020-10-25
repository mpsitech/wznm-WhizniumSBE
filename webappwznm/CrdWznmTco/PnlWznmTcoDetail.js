/**
  * \file PnlWznmTcoDetail.js
  * web client functionality for panel PnlWznmTcoDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmTcoDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTcoDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmTcoDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTcoDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmTcoDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSho", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptSho"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptTbl", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptTbl"));
	initCpt(contcontdoc, "CptSbs", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptSbs"));
	initCpt(contcontdoc, "CptRel", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptRel"));
	initCpt(contcontdoc, "CptFcu", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptFcu"));
	refreshPup(contcontdoc, srcdoc, "PupFct", "xs", "FeedFPupFct", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupFct"), true, false);
	initCpt(contcontdoc, "CptSty", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptSty"));
	refreshPup(contcontdoc, srcdoc, "PupSty", "", "FeedFPupSty", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupSty"), retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupStyActive"), false);
	initCpt(contcontdoc, "CptAxf", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptAxf"));
	refreshPup(contcontdoc, srcdoc, "PupAxf", "", "FeedFPupAxf", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupAxf"), retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupAxfActive"), false);
	initCpt(contcontdoc, "CptPnc", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptPnc"));
	initCpt(contcontdoc, "CptEpo", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptEpo"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtSrfActive") == "true");

	var TxfShoActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxfShoActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupTypActive") == "true");

	var TxtTblActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtTblActive") == "true");
	var ButTblViewAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButTblViewAvail") == "true");
	var ButTblViewActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButTblViewActive") == "true");

	var TxtSbsAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtSbsAvail") == "true");
	var TxtSbsActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtSbsActive") == "true");
	var ButSbsViewAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButSbsViewAvail") == "true");
	var ButSbsViewActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButSbsViewActive") == "true");

	var TxtRelAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtRelAvail") == "true");
	var TxtRelActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtRelActive") == "true");
	var ButRelViewAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButRelViewAvail") == "true");
	var ButRelViewActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButRelViewActive") == "true");

	var TxtFcuAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtFcuAvail") == "true");
	var TxtFcuActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxtFcuActive") == "true");
	var ButFcuViewAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButFcuViewAvail") == "true");
	var ButFcuViewActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButFcuViewActive") == "true");

	var PupStyActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupStyActive") == "true");

	var PupAxfActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "PupAxfActive") == "true");

	var LstOptAlt = (retrieveSi(srcdoc, "StatAppWznmTcoDetail", "LstOptAlt") == "true");
	var TxfOptValid = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "TxfOptValid") == "true");
	var LstOptActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "LstOptActive") == "true");
	var ButOptEditAvail = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButOptEditAvail") == "true");

	var ChkPncActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ChkPncActive") == "true");

	var ChkEpoActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ChkEpoActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmTcoDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmTcoDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfSho", "xs", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "TxfSho"), TxfShoActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupTyp");

	if ((ButTblViewAvail == !contcontdoc.getElementById("ButTblView"))) {
		mytd = contcontdoc.getElementById("rdynTbl");
		clearElem(mytd);

		first = true;

		if (ButTblViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTblView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTbl", retrieveCi(srcdoc, "ContInfWznmTcoDetail", "TxtTbl"));

	if (ButTblViewAvail) refreshButicon(contcontdoc, "ButTblView", "icon/view", ButTblViewActive, false);

	height -= setCtlAvail(contcontdoc, "Sbs", TxtSbsAvail, 25);
	if (TxtSbsAvail) {
		if ((ButSbsViewAvail == !contcontdoc.getElementById("ButSbsView"))) {
			mytd = contcontdoc.getElementById("rdynSbs");
			clearElem(mytd);

			first = true;

			if (ButSbsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSbsView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtSbs", retrieveCi(srcdoc, "ContInfWznmTcoDetail", "TxtSbs"));

		if (ButSbsViewAvail) refreshButicon(contcontdoc, "ButSbsView", "icon/view", ButSbsViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "Rel", TxtRelAvail, 25);
	if (TxtRelAvail) {
		if ((ButRelViewAvail == !contcontdoc.getElementById("ButRelView"))) {
			mytd = contcontdoc.getElementById("rdynRel");
			clearElem(mytd);

			first = true;

			if (ButRelViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRelView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtRel", retrieveCi(srcdoc, "ContInfWznmTcoDetail", "TxtRel"));

		if (ButRelViewAvail) refreshButicon(contcontdoc, "ButRelView", "icon/view", ButRelViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "Fcu", TxtFcuAvail, 25);
	if (TxtFcuAvail) {
		if ((ButFcuViewAvail == !contcontdoc.getElementById("ButFcuView"))) {
			mytd = contcontdoc.getElementById("rdynFcu");
			clearElem(mytd);

			first = true;

			if (ButFcuViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFcuView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtFcu", retrieveCi(srcdoc, "ContInfWznmTcoDetail", "TxtFcu"));
		contcontdoc.getElementById("PupFct").value = retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupFct");

		if (ButFcuViewAvail) refreshButicon(contcontdoc, "ButFcuView", "icon/view", ButFcuViewActive, false);

	};

	contcontdoc.getElementById("PupSty").value = retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupSty");

	contcontdoc.getElementById("PupAxf").value = retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numFPupAxf");

	height -= setCtlAvail(contcontdoc, "Opt2", !LstOptAlt, 71);
	if ( (LstOptAlt == !contcontdoc.getElementById("ButOptExpand")) || (!LstOptAlt == !contcontdoc.getElementById("ButOptCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOpt");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpt", retrieveTi(srcdoc, "TagWznmTcoDetail", "CptOpt")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstOptAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOptExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButOptCollapse", "icon/collapse"));
	};

	if ( (LstOptAlt == !contcontdoc.getElementById("TxfOpt")) || (!LstOptAlt == !contcontdoc.getElementById("LstOpt")) ) {
		mytd = contcontdoc.getElementById("dynOpt");
		clearElem(mytd);

		if (LstOptAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfOpt", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOpt", "./PnlWznmTcoDetail_LstOpt.xml", false));
		};

	} else {
		if (!LstOptAlt) refreshLst(contcontdoc.getElementById("LstOpt").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOpt",
					parseInt(retrieveSi(srcdoc, "StatAppWznmTcoDetail", "LstOptNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numsFLstOpt")));
	};

	if (LstOptAlt) refreshTxf(contcontdoc, "TxfOpt", "", retrieveCi(srcdoc, "ContIacWznmTcoDetail", "TxfOpt"), LstOptActive, false, TxfOptValid);

	if ((ButOptEditAvail == !contcontdoc.getElementById("ButOptEdit"))) {
		mytd = contcontdoc.getElementById("rdynOpt");
		clearElem(mytd);

		first = true;

		if (ButOptEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOptEdit", "icon/edit"));
		};
	};

	refreshChk(contcontdoc, "ChkPnc", (retrieveCi(srcdoc, "ContIacWznmTcoDetail", "ChkPnc") == "true"), ChkPncActive);

	refreshChk(contcontdoc, "ChkEpo", (retrieveCi(srcdoc, "ContIacWznmTcoDetail", "ChkEpo") == "true"), ChkEpoActive);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTcoDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmTcoDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmTcoDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTcoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWznmTcoDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTcoDetailData", scrJref, "ContIacWznmTcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmTcoDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmTcoDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmTcoDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmTcoDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTcoDetailData", scrJref, "ContIacWznmTcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmTcoDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmTcoDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmTcoDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmTcoDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTcoDetailData", scrJref, "ContIacWznmTcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmTcoDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmTcoDetailData", scrJref, "ContIacWznmTcoDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmTcoDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTcoDetailData", scrJref, "ContIacWznmTcoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "ContIacWznmTcoDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "ContInfWznmTcoDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "FeedFLstOpt", srcdoc)) mask.push("feedFLstOpt");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "FeedFPupAxf", srcdoc)) mask.push("feedFPupAxf");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "FeedFPupFct", srcdoc)) mask.push("feedFPupFct");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "FeedFPupSty", srcdoc)) mask.push("feedFPupSty");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "StatAppWznmTcoDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "StatShrWznmTcoDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmTcoDetailData", "TagWznmTcoDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmTcoDetailData") {
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
			if (blk.nodeName == "DpchEngWznmTcoDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmTcoDetailData") {
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

