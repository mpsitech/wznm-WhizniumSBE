// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmTblDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTblDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmTblDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmTblDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmTblDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmTblDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSho", retrieveTi(srcdoc, "TagWznmTblDetail", "CptSho"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmTblDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmTblDetail", "CptVer"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmTblDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptCar", retrieveTi(srcdoc, "TagWznmTblDetail", "CptCar"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmTblDetail", "CptCmt"));
	initCpt(contcontdoc, "CptPstSrf", retrieveTi(srcdoc, "TagWznmTblDetail", "CptPstSrf"));
	initCpt(contcontdoc, "CptPstTit", retrieveTi(srcdoc, "TagWznmTblDetail", "CptPstTit"));
	initCpt(contcontdoc, "CptPstVer", retrieveTi(srcdoc, "TagWznmTblDetail", "CptPstVer"));
	initCpt(contcontdoc, "CptPstSco", retrieveTi(srcdoc, "TagWznmTblDetail", "CptPstSco"));
	refreshPup(contcontdoc, srcdoc, "PupPstSco", "", "FeedFPupPstSco", retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupPstSco"), retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstScoActive"), false);
	initCpt(contcontdoc, "CptPstAty", retrieveTi(srcdoc, "TagWznmTblDetail", "CptPstAty"));
	refreshPup(contcontdoc, srcdoc, "PupPstAty", "", "FeedFPupPstAty", retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupPstAty"), retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstAtyActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate");

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

	var height = 520; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtSrfActive") == "true");

	var TxfShoActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxfShoActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupTypActive") == "true");

	var TxtVerActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtVerActive") == "true");
	var ButVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButVerViewAvail") == "true");
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButVerViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButReuViewActive") == "true");

	var TxtCarAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtCarAvail") == "true");
	var TxtCarActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtCarActive") == "true");
	var ButCarViewAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButCarViewAvail") == "true");
	var ButCarViewActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButCarViewActive") == "true");

	var LstUnqAlt = (retrieveSi(srcdoc, "StatAppWznmTblDetail", "LstUnqAlt") == "true");
	var TxfUnqValid = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxfUnqValid") == "true");
	var LstUnqAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "LstUnqAvail") == "true");
	var LstUnqActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "LstUnqActive") == "true");
	var ButUnqViewAvail = !LstUnqAlt && (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButUnqViewAvail") == "true");;
	var ButUnqViewActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButUnqViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxfCmtActive") == "true");

	var SepPstAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "SepPstAvail") == "true");

	var HdgPstAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "HdgPstAvail") == "true");
	var ButPstNewAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButPstNewAvail") == "true");
	var ButPstDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButPstDeleteAvail") == "true");

	var TxtPstSrfAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstSrfAvail") == "true");
	var TxtPstSrfActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstSrfActive") == "true");

	var PupPstJtiAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstJtiAvail") == "true");
	var PupPstJtiActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstJtiActive") == "true");
	var ButPstJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButPstJtiEditAvail") == "true");

	var TxtPstTitAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstTitAvail") == "true");
	var TxtPstTitActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstTitActive") == "true");

	var TxtPstVerAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstVerAvail") == "true");
	var TxtPstVerActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "TxtPstVerActive") == "true");
	var ButPstVerViewAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButPstVerViewAvail") == "true");
	var ButPstVerViewActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButPstVerViewActive") == "true");

	var PupPstScoAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstScoAvail") == "true");
	var PupPstScoActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstScoActive") == "true");

	var PupPstAtyAvail = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstAtyAvail") == "true");
	var PupPstAtyActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "PupPstAtyActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmTblDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfSho", "xs", retrieveCi(srcdoc, "ContIacWznmTblDetail", "TxfSho"), TxfShoActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtVer", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtVer"));

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

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	height -= setCtlAvail(contcontdoc, "Car", TxtCarAvail, 25);
	if (TxtCarAvail) {
		if ((ButCarViewAvail == !contcontdoc.getElementById("ButCarView"))) {
			mytd = contcontdoc.getElementById("rdynCar");
			clearElem(mytd);

			first = true;

			if (ButCarViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCarView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtCar", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtCar"));

		if (ButCarViewAvail) refreshButicon(contcontdoc, "ButCarView", "icon/view", ButCarViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "Unq", LstUnqAvail, 96);
	height -= setCtlAvail(contcontdoc, "Unq2", LstUnqAvail && !LstUnqAlt, (LstUnqAvail) ? 71 : 0);
	if (LstUnqAvail) {
		if ( (LstUnqAlt == !contcontdoc.getElementById("ButUnqExpand")) || (!LstUnqAlt == !contcontdoc.getElementById("ButUnqCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUnq");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUnq", retrieveTi(srcdoc, "TagWznmTblDetail", "CptUnq")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUnqAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUnqExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUnqCollapse", "icon/collapse"));
		};

		if ( (LstUnqAlt == !contcontdoc.getElementById("TxfUnq")) || (!LstUnqAlt == !contcontdoc.getElementById("LstUnq")) ) {
			mytd = contcontdoc.getElementById("dynUnq");
			clearElem(mytd);

			if (LstUnqAlt) {
				mytd.setAttribute("rowspan", "1");
				mytd.appendChild(makeInputTxf(contcontdoc, "TxfUnq", ""));
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUnq", "./PnlWznmTblDetail_LstUnq.xml", false));
			};

		} else {
			if (!LstUnqAlt) refreshLst(contcontdoc.getElementById("LstUnq").contentWindow.document, srcdoc, 1, false, false, "FeedFLstUnq",
						parseInt(retrieveSi(srcdoc, "StatAppWznmTblDetail", "LstUnqNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFLstUnq"))]);
		};

		if (LstUnqAlt) refreshTxf(contcontdoc, "TxfUnq", "", retrieveCi(srcdoc, "ContIacWznmTblDetail", "TxfUnq"), LstUnqActive, false, TxfUnqValid);

		if ((ButUnqViewAvail == !contcontdoc.getElementById("ButUnqView"))) {
			mytd = contcontdoc.getElementById("rdynUnq");
			clearElem(mytd);

			first = true;

			if (ButUnqViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUnqView", "icon/view"));
			};
		};

		if (ButUnqViewAvail) refreshButicon(contcontdoc, "ButUnqView", "icon/view", ButUnqViewActive, false);

	} else setCtlAvail(contcontdoc, "Unq2", false, 0);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmTblDetail", "TxfCmt"), TxfCmtActive, false, true);

	height -= setCtlAvail(contcontdoc, "Pst1", SepPstAvail, 0);
	setCtlAvail(contcontdoc, "Pst2", SepPstAvail, 7);
	setCtlAvail(contcontdoc, "Pst3", SepPstAvail, 0);
	if (SepPstAvail) {

	};

	height -= setCtlAvail(contcontdoc, "Pst", HdgPstAvail, 25);
	if (HdgPstAvail) {
		if ((ButPstNewAvail == !contcontdoc.getElementById("ButPstNew")) || (ButPstDeleteAvail == !contcontdoc.getElementById("ButPstDelete"))) {
			mytd = contcontdoc.getElementById("dynPst");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "HdgPst", retrieveTi(srcdoc, "TagWznmTblDetail", "HdgPst")));
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

	};

	height -= setCtlAvail(contcontdoc, "PstSrf", TxtPstSrfAvail, 25);
	if (TxtPstSrfAvail) {
		refreshTxt(contcontdoc, "TxtPstSrf", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtPstSrf"));

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

		refreshPup(contcontdoc, srcdoc, "PupPstJti", "s", "FeedFPupPstJti", retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupPstJti"), PupPstJtiActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstTit", TxtPstTitAvail, 25);
	if (TxtPstTitAvail) {
		refreshTxt(contcontdoc, "TxtPstTit", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtPstTit"));

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

		refreshTxt(contcontdoc, "TxtPstVer", retrieveCi(srcdoc, "ContInfWznmTblDetail", "TxtPstVer"));

		if (ButPstVerViewAvail) refreshButicon(contcontdoc, "ButPstVerView", "icon/view", ButPstVerViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "PstSco", PupPstScoAvail, 25);
	if (PupPstScoAvail) {
		contcontdoc.getElementById("PupPstSco").value = retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupPstSco");

	};

	height -= setCtlAvail(contcontdoc, "PstAty", PupPstAtyAvail, 25);
	if (PupPstAtyAvail) {
		contcontdoc.getElementById("PupPstAty").value = retrieveCi(srcdoc, "ContIacWznmTblDetail", "numFPupPstAty");

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmTblDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmTblDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmTblDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTblDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTblDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTblDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmTblDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmTblDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmTblDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmTblDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTblDetailData", scrJref, "ContIacWznmTblDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmTblDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmTblDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmTblDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmTblDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTblDetailData", scrJref, "ContIacWznmTblDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmTblDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmTblDetailData", scrJref, "ContIacWznmTblDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmTblDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTblDetailData", scrJref, "ContIacWznmTblDetail");
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

	setCi(srcdoc, "ContIacWznmTblDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmTblDetailData", scrJref, "ContIacWznmTblDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "ContIacWznmTblDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "ContInfWznmTblDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFLstUnq", srcdoc)) mask.push("feedFLstUnq");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFPupPstAty", srcdoc)) mask.push("feedFPupPstAty");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFPupPstJti", srcdoc)) mask.push("feedFPupPstJti");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFPupPstSco", srcdoc)) mask.push("feedFPupPstSco");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "StatAppWznmTblDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "StatShrWznmTblDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmTblDetailData", "TagWznmTblDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmTblDetailData") {
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
			if (blk.nodeName == "DpchEngWznmTblDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmTblDetailData") {
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
