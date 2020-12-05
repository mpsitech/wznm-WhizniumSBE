// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Appdev", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Appdev_side").setAttribute("height", "30");
	doc.getElementById("Appdev_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Appdev_side").src = "./PnlWznmNavAppdev_aside.html";
	doc.getElementById("Appdev_cont").src = "./PnlWznmNavAppdev_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Appdev_side").src = "./PnlWznmNavAppdev_bside.html";
	doc.getElementById("Appdev_cont").src = "./PnlWznmNavAppdev_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Appdev_side").contentDocument;
	contdoc = doc.getElementById("Appdev_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavAppdev", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Appdev_side").contentDocument;
	contdoc = doc.getElementById("Appdev_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Appdev_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Appdev_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavAppdev", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate");

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

	var height = 490; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstAppAlt = (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstAppAlt") == "true");
	var LstAppAvail = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "LstAppAvail") == "true");
	var ButAppViewAvail = !LstAppAlt;
	var ButAppViewActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButAppViewActive") == "true");

	var LstRtjAlt = (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstRtjAlt") == "true");
	var LstRtjAvail = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "LstRtjAvail") == "true");
	var ButRtjViewAvail = !LstRtjAlt;
	var ButRtjViewActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButRtjViewActive") == "true");
	var ButRtjNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButRtjNewcrdActive") == "true");

	var LstEvtAlt = (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstEvtAlt") == "true");
	var LstEvtAvail = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "LstEvtAvail") == "true");
	var ButEvtViewAvail = !LstEvtAlt;
	var ButEvtViewActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButEvtViewActive") == "true");
	var ButEvtNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButEvtNewcrdActive") == "true");

	var LstSeqAlt = (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstSeqAlt") == "true");
	var LstSeqAvail = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "LstSeqAvail") == "true");
	var ButSeqViewAvail = !LstSeqAlt;
	var ButSeqViewActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButSeqViewActive") == "true");
	var ButSeqNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButSeqNewcrdActive") == "true");

	var LstSteAlt = (retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstSteAlt") == "true");
	var LstSteAvail = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "LstSteAvail") == "true");
	var ButSteViewAvail = !LstSteAlt;
	var ButSteViewActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButSteViewActive") == "true");
	var ButSteNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavAppdev", "ButSteNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "App", LstAppAvail, 96);
	height -= setCtlAvail(contcontdoc, "App2", LstAppAvail && !LstAppAlt, (LstAppAvail) ? 71 : 0);
	if (LstAppAvail) {
		if ( (LstAppAlt == !contcontdoc.getElementById("ButAppExpand")) || (!LstAppAlt == !contcontdoc.getElementById("ButAppCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynApp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptApp", retrieveTi(srcdoc, "TagWznmNavAppdev", "CptApp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstAppAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButAppExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButAppCollapse", "icon/collapse"));
		};

		if (!LstAppAlt == !contcontdoc.getElementById("LstApp")) {
			mytd = contcontdoc.getElementById("rdynApp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynApp");
			clearElem(mytd);

			if (LstAppAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstApp", "./PnlWznmNavAppdev_LstApp.xml", true));
			};

		} else {
			if (!LstAppAlt) refreshLst(contcontdoc.getElementById("LstApp").contentWindow.document, srcdoc, 1, true, false, "FeedFLstApp",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstAppNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numFLstApp"))]);
		};

		if ((ButAppViewAvail == !contcontdoc.getElementById("ButAppView")) || !contcontdoc.getElementById("ButAppNewcrd")) {
			if (LstAppAlt) mytd = contcontdoc.getElementById("dynApp");
			else mytd = contcontdoc.getElementById("rdynApp");
			clearElem(mytd);

			first = true;

			if (ButAppViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButAppView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAppNewcrd", "icon/newcrd"));
		};

		if (ButAppViewAvail) refreshButicon(contcontdoc, "ButAppView", "icon/view", ButAppViewActive, false);

	} else setCtlAvail(contcontdoc, "App2", false, 0);

	height -= setCtlAvail(contcontdoc, "Rtj", LstRtjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Rtj2", LstRtjAvail && !LstRtjAlt, (LstRtjAvail) ? 71 : 0);
	if (LstRtjAvail) {
		if ( (LstRtjAlt == !contcontdoc.getElementById("ButRtjExpand")) || (!LstRtjAlt == !contcontdoc.getElementById("ButRtjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRtj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRtj", retrieveTi(srcdoc, "TagWznmNavAppdev", "CptRtj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRtjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRtjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRtjCollapse", "icon/collapse"));
		};

		if (!LstRtjAlt == !contcontdoc.getElementById("LstRtj")) {
			mytd = contcontdoc.getElementById("rdynRtj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRtj");
			clearElem(mytd);

			if (LstRtjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRtj", "./PnlWznmNavAppdev_LstRtj.xml", true));
			};

		} else {
			if (!LstRtjAlt) refreshLst(contcontdoc.getElementById("LstRtj").contentWindow.document, srcdoc, 1, true, false, "FeedFLstRtj",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstRtjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numFLstRtj"))]);
		};

		if ((ButRtjViewAvail == !contcontdoc.getElementById("ButRtjView")) || !contcontdoc.getElementById("ButRtjNewcrd")) {
			if (LstRtjAlt) mytd = contcontdoc.getElementById("dynRtj");
			else mytd = contcontdoc.getElementById("rdynRtj");
			clearElem(mytd);

			first = true;

			if (ButRtjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRtjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRtjNewcrd", "icon/newcrd"));
		};

		if (ButRtjViewAvail) refreshButicon(contcontdoc, "ButRtjView", "icon/view", ButRtjViewActive, false);
		refreshButicon(contcontdoc, "ButRtjNewcrd", "icon/newcrd", ButRtjNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Rtj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Evt", LstEvtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Evt2", LstEvtAvail && !LstEvtAlt, (LstEvtAvail) ? 71 : 0);
	if (LstEvtAvail) {
		if ( (LstEvtAlt == !contcontdoc.getElementById("ButEvtExpand")) || (!LstEvtAlt == !contcontdoc.getElementById("ButEvtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynEvt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptEvt", retrieveTi(srcdoc, "TagWznmNavAppdev", "CptEvt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstEvtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButEvtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButEvtCollapse", "icon/collapse"));
		};

		if (!LstEvtAlt == !contcontdoc.getElementById("LstEvt")) {
			mytd = contcontdoc.getElementById("rdynEvt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynEvt");
			clearElem(mytd);

			if (LstEvtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstEvt", "./PnlWznmNavAppdev_LstEvt.xml", true));
			};

		} else {
			if (!LstEvtAlt) refreshLst(contcontdoc.getElementById("LstEvt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstEvt",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstEvtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numFLstEvt"))]);
		};

		if ((ButEvtViewAvail == !contcontdoc.getElementById("ButEvtView")) || !contcontdoc.getElementById("ButEvtNewcrd")) {
			if (LstEvtAlt) mytd = contcontdoc.getElementById("dynEvt");
			else mytd = contcontdoc.getElementById("rdynEvt");
			clearElem(mytd);

			first = true;

			if (ButEvtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButEvtView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEvtNewcrd", "icon/newcrd"));
		};

		if (ButEvtViewAvail) refreshButicon(contcontdoc, "ButEvtView", "icon/view", ButEvtViewActive, false);
		refreshButicon(contcontdoc, "ButEvtNewcrd", "icon/newcrd", ButEvtNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Evt2", false, 0);

	height -= setCtlAvail(contcontdoc, "Seq", LstSeqAvail, 96);
	height -= setCtlAvail(contcontdoc, "Seq2", LstSeqAvail && !LstSeqAlt, (LstSeqAvail) ? 71 : 0);
	if (LstSeqAvail) {
		if ( (LstSeqAlt == !contcontdoc.getElementById("ButSeqExpand")) || (!LstSeqAlt == !contcontdoc.getElementById("ButSeqCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSeq");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSeq", retrieveTi(srcdoc, "TagWznmNavAppdev", "CptSeq")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSeqAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSeqExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSeqCollapse", "icon/collapse"));
		};

		if (!LstSeqAlt == !contcontdoc.getElementById("LstSeq")) {
			mytd = contcontdoc.getElementById("rdynSeq");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSeq");
			clearElem(mytd);

			if (LstSeqAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSeq", "./PnlWznmNavAppdev_LstSeq.xml", true));
			};

		} else {
			if (!LstSeqAlt) refreshLst(contcontdoc.getElementById("LstSeq").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSeq",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstSeqNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numFLstSeq"))]);
		};

		if ((ButSeqViewAvail == !contcontdoc.getElementById("ButSeqView")) || !contcontdoc.getElementById("ButSeqNewcrd")) {
			if (LstSeqAlt) mytd = contcontdoc.getElementById("dynSeq");
			else mytd = contcontdoc.getElementById("rdynSeq");
			clearElem(mytd);

			first = true;

			if (ButSeqViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSeqView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSeqNewcrd", "icon/newcrd"));
		};

		if (ButSeqViewAvail) refreshButicon(contcontdoc, "ButSeqView", "icon/view", ButSeqViewActive, false);
		refreshButicon(contcontdoc, "ButSeqNewcrd", "icon/newcrd", ButSeqNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Seq2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ste", LstSteAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ste2", LstSteAvail && !LstSteAlt, (LstSteAvail) ? 71 : 0);
	if (LstSteAvail) {
		if ( (LstSteAlt == !contcontdoc.getElementById("ButSteExpand")) || (!LstSteAlt == !contcontdoc.getElementById("ButSteCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSte");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWznmNavAppdev", "CptSte")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSteAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSteExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSteCollapse", "icon/collapse"));
		};

		if (!LstSteAlt == !contcontdoc.getElementById("LstSte")) {
			mytd = contcontdoc.getElementById("rdynSte");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSte");
			clearElem(mytd);

			if (LstSteAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSte", "./PnlWznmNavAppdev_LstSte.xml", true));
			};

		} else {
			if (!LstSteAlt) refreshLst(contcontdoc.getElementById("LstSte").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSte",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", "LstSteNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numFLstSte"))]);
		};

		if ((ButSteViewAvail == !contcontdoc.getElementById("ButSteView")) || !contcontdoc.getElementById("ButSteNewcrd")) {
			if (LstSteAlt) mytd = contcontdoc.getElementById("dynSte");
			else mytd = contcontdoc.getElementById("rdynSte");
			clearElem(mytd);

			first = true;

			if (ButSteViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSteView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSteNewcrd", "icon/newcrd"));
		};

		if (ButSteViewAvail) refreshButicon(contcontdoc, "ButSteView", "icon/view", ButSteViewActive, false);
		refreshButicon(contcontdoc, "ButSteNewcrd", "icon/newcrd", ButSteNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Ste2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Appdev", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Appdev_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Appdev_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Appdev_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavAppdev", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Appdev_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavAppdev", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavAppdev", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavAppdevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavAppdevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavAppdev", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavAppdev", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavAppdevData", scrJref, "ContIacWznmNavAppdev");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavAppdev", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavAppdev", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavAppdev", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "ContIacWznmNavAppdev", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "FeedFLstApp", srcdoc)) mask.push("feedFLstApp");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "FeedFLstEvt", srcdoc)) mask.push("feedFLstEvt");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "FeedFLstRtj", srcdoc)) mask.push("feedFLstRtj");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "FeedFLstSeq", srcdoc)) mask.push("feedFLstSeq");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "FeedFLstSte", srcdoc)) mask.push("feedFLstSte");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "StatAppWznmNavAppdev", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "StatShrWznmNavAppdev", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavAppdevData", "TagWznmNavAppdev", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavAppdevData") {
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
			if (blk.nodeName == "DpchEngWznmNavAppdevData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Appdev");
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

			} else if (blk.nodeName == "DpchEngWznmNavAppdevData") {
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

