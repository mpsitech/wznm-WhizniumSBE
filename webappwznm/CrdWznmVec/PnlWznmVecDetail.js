/**
  * \file PnlWznmVecDetail.js
  * web client functionality for panel PnlWznmVecDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmVecDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVecDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmVecDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmVecDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmVecDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmVecDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmVecDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmVecDetail", "CptVer"));
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagWznmVecDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptTgr", retrieveTi(srcdoc, "TagWznmVecDetail", "CptTgr"));
	initCpt(contcontdoc, "CptPstSrf", retrieveTi(srcdoc, "TagWznmVecDetail", "CptPstSrf"));
	initCpt(contcontdoc, "CptPstTit", retrieveTi(srcdoc, "TagWznmVecDetail", "CptPstTit"));
	initCpt(contcontdoc, "CptPstVer", retrieveTi(srcdoc, "TagWznmVecDetail", "CptPstVer"));
	initCpt(contcontdoc, "CptPstSco", retrieveTi(srcdoc, "TagWznmVecDetail", "CptPstSco"));
	refreshPup(contcontdoc, srcdoc, "PupPstSco", "", "FeedFPupPstSco", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupPstSco"), retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstScoActive"), false);
	initCpt(contcontdoc, "CptPstAty", retrieveTi(srcdoc, "TagWznmVecDetail", "CptPstAty"));
	refreshPup(contcontdoc, srcdoc, "PupPstAty", "", "FeedFPupPstAty", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupPstAty"), retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstAtyActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate");

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

	var height = 420; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtSrfActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupTypActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButVerViewActive") == "true");

	var TxtHkuActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtHkuActive") == "true");
	var ButHkuViewAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButHkuViewAvail") == "true");
	var ButHkuViewActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButHkuViewActive") == "true");

	var PupTgrAlt = (retrieveSi(srcdoc, "StatAppWznmVecDetail", "PupTgrAlt") == "true");
	var TxfTgrValid = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxfTgrValid") == "true");
	var PupTgrActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupTgrActive") == "true");
	var ButTgrEditAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButTgrEditAvail") == "true");

	var LstOptAlt = (retrieveSi(srcdoc, "StatAppWznmVecDetail", "LstOptAlt") == "true");
	var TxfOptValid = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxfOptValid") == "true");
	var LstOptActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "LstOptActive") == "true");
	var ButOptEditAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButOptEditAvail") == "true");

	var ButPstNewAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButPstNewAvail") == "true");
	var ButPstDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButPstDeleteAvail") == "true");

	var TxtPstSrfAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstSrfAvail") == "true");
	var TxtPstSrfActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstSrfActive") == "true");

	var PupPstJtiAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstJtiAvail") == "true");
	var PupPstJtiActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstJtiActive") == "true");
	var ButPstJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButPstJtiEditAvail") == "true");

	var TxtPstTitAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstTitAvail") == "true");
	var TxtPstTitActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstTitActive") == "true");

	var TxtPstVerAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstVerAvail") == "true");
	var TxtPstVerActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "TxtPstVerActive") == "true");
	var ButPstVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButPstVerViewAvail") == "true");
	var ButPstVerViewActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButPstVerViewActive") == "true");

	var PupPstScoAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstScoAvail") == "true");
	var PupPstScoActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstScoActive") == "true");

	var PupPstAtyAvail = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstAtyAvail") == "true");
	var PupPstAtyActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "PupPstAtyActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmVecDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtVer"));

	if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	if ((ButHkuViewAvail == !contcontdoc.getElementById("ButHkuView"))) {
		mytd = contcontdoc.getElementById("rdynHku");
		clearElem(mytd);

		first = true;

		if (ButHkuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHkuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupHkt");

	if (ButHkuViewAvail) refreshButicon(contcontdoc, "ButHkuView", "icon/view", ButHkuViewActive, false);

	if ( (PupTgrAlt == !contcontdoc.getElementById("TxfTgr")) || (!PupTgrAlt == !contcontdoc.getElementById("PupTgr")) ) {
		mytd = contcontdoc.getElementById("dynTgr");
		clearElem(mytd);

		if (PupTgrAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfTgr", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupTgr", ""));
	};

	if (PupTgrAlt) refreshTxf(contcontdoc, "TxfTgr", "", retrieveCi(srcdoc, "ContIacWznmVecDetail", "TxfTgr"), PupTgrActive, false, TxfTgrValid);
	else refreshPup(contcontdoc, srcdoc, "PupTgr", "", "FeedFPupTgr", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupTgr"), true, false);

	if ((ButTgrEditAvail == !contcontdoc.getElementById("ButTgrEdit"))) {
		mytd = contcontdoc.getElementById("rdynTgr");
		clearElem(mytd);

		first = true;

		if (ButTgrEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTgrEdit", "icon/edit"));
		};
	};

	height -= setCtlAvail(contcontdoc, "Opt2", !LstOptAlt, 71);
	if ( (LstOptAlt == !contcontdoc.getElementById("ButOptExpand")) || (!LstOptAlt == !contcontdoc.getElementById("ButOptCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOpt");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpt", retrieveTi(srcdoc, "TagWznmVecDetail", "CptOpt")));

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
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOpt", "./PnlWznmVecDetail_LstOpt.xml", false));
		};

	} else {
		if (!LstOptAlt) refreshLst(contcontdoc.getElementById("LstOpt").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOpt",
					parseInt(retrieveSi(srcdoc, "StatAppWznmVecDetail", "LstOptNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numsFLstOpt")));
	};

	if (LstOptAlt) refreshTxf(contcontdoc, "TxfOpt", "", retrieveCi(srcdoc, "ContIacWznmVecDetail", "TxfOpt"), LstOptActive, false, TxfOptValid);

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

	if ((ButPstNewAvail == !contcontdoc.getElementById("ButPstNew")) || (ButPstDeleteAvail == !contcontdoc.getElementById("ButPstDelete"))) {
		mytd = contcontdoc.getElementById("dynPst");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgPst", retrieveTi(srcdoc, "TagWznmVecDetail", "HdgPst")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButPstNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstNew", "icon/new"));
		};

		if (ButPstDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "PstSrf", TxtPstSrfAvail, 25);
	if (TxtPstSrfAvail) {
		refreshTxt(contcontdoc, "TxtPstSrf", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtPstSrf"));

	};

	height -= setCtlAvail(contcontdoc, "PstJti", PupPstJtiAvail, 25);
	if (PupPstJtiAvail) {
		if ((ButPstJtiEditAvail == !contcontdoc.getElementById("ButPstJtiEdit"))) {
			mytd = contcontdoc.getElementById("rdynPstJti");
			clearElem(mytd);

			first = true;

			if (ButPstJtiEditAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstJtiEdit", "icon/edit"));
			};
		};

		refreshPup(contcontdoc, srcdoc, "PupPstJti", "s", "FeedFPupPstJti", retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupPstJti"), PupPstJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstTit", TxtPstTitAvail, 25);
	if (TxtPstTitAvail) {
		refreshTxt(contcontdoc, "TxtPstTit", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtPstTit"));

	};

	height -= setCtlAvail(contcontdoc, "PstVer", TxtPstVerAvail, 25);
	if (TxtPstVerAvail) {
		if ((ButPstVerViewAvail == !contcontdoc.getElementById("ButPstVerView"))) {
			mytd = contcontdoc.getElementById("rdynPstVer");
			clearElem(mytd);

			first = true;

			if (ButPstVerViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstVerView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtPstVer", retrieveCi(srcdoc, "ContInfWznmVecDetail", "TxtPstVer"));

		if (ButPstVerViewAvail) refreshButicon(contcontdoc, "ButPstVerView", "icon/view", ButPstVerViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstSco", PupPstScoAvail, 25);
	if (PupPstScoAvail) {
		contcontdoc.getElementById("PupPstSco").value = retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupPstSco");

	};

	height -= setCtlAvail(contcontdoc, "PstAty", PupPstAtyAvail, 25);
	if (PupPstAtyAvail) {
		contcontdoc.getElementById("PupPstAty").value = retrieveCi(srcdoc, "ContIacWznmVecDetail", "numFPupPstAty");

	};

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmVecDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmVecDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmVecDetail", basectlsref + "Alt", "false");
	refresh();
};

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWznmVecDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWznmVecDetail", basectlsref + "Alt", alt);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVecDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVecDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVecDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmVecDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmVecDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmVecDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmVecDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVecDetailData", scrJref, "ContIacWznmVecDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmVecDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmVecDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmVecDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmVecDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVecDetailData", scrJref, "ContIacWznmVecDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmVecDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmVecDetailData", scrJref, "ContIacWznmVecDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmVecDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmVecDetailData", scrJref, "ContIacWznmVecDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "ContIacWznmVecDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "ContInfWznmVecDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFLstOpt", srcdoc)) mask.push("feedFLstOpt");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupPstAty", srcdoc)) mask.push("feedFPupPstAty");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupPstJti", srcdoc)) mask.push("feedFPupPstJti");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupPstSco", srcdoc)) mask.push("feedFPupPstSco");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupTgr", srcdoc)) mask.push("feedFPupTgr");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "StatAppWznmVecDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "StatShrWznmVecDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVecDetailData", "TagWznmVecDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmVecDetailData") {
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
			if (blk.nodeName == "DpchEngWznmVecDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmVecDetailData") {
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

