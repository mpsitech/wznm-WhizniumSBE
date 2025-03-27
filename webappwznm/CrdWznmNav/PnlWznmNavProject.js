// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Project", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Project_side").setAttribute("height", "30");
	doc.getElementById("Project_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Project_side").src = "./PnlWznmNavProject_aside.html";
	doc.getElementById("Project_cont").src = "./PnlWznmNavProject_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Project_side").src = "./PnlWznmNavProject_bside.html";
	doc.getElementById("Project_cont").src = "./PnlWznmNavProject_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Project_side").contentDocument;
	contdoc = doc.getElementById("Project_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavProject", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Project_side").contentDocument;
	contdoc = doc.getElementById("Project_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Project_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Project_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavProject", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate");

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

	var height = 394; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstPrjAlt = (retrieveSi(srcdoc, "StatAppWznmNavProject", "LstPrjAlt") == "true");
	var LstPrjAvail = (retrieveSi(srcdoc, "StatShrWznmNavProject", "LstPrjAvail") == "true");
	var ButPrjViewAvail = !LstPrjAlt;
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButPrjViewActive") == "true");

	var LstVerAlt = (retrieveSi(srcdoc, "StatAppWznmNavProject", "LstVerAlt") == "true");
	var LstVerAvail = (retrieveSi(srcdoc, "StatShrWznmNavProject", "LstVerAvail") == "true");
	var ButVerViewAvail = !LstVerAlt;
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButVerViewActive") == "true");

	var LstCapAlt = (retrieveSi(srcdoc, "StatAppWznmNavProject", "LstCapAlt") == "true");
	var LstCapAvail = (retrieveSi(srcdoc, "StatShrWznmNavProject", "LstCapAvail") == "true");
	var ButCapViewAvail = !LstCapAlt;
	var ButCapViewActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButCapViewActive") == "true");
	var ButCapNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButCapNewcrdActive") == "true");

	var LstErrAlt = (retrieveSi(srcdoc, "StatAppWznmNavProject", "LstErrAlt") == "true");
	var LstErrAvail = (retrieveSi(srcdoc, "StatShrWznmNavProject", "LstErrAvail") == "true");
	var ButErrViewAvail = !LstErrAlt;
	var ButErrViewActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButErrViewActive") == "true");
	var ButErrNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavProject", "ButErrNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Prj", LstPrjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prj2", LstPrjAvail && !LstPrjAlt, (LstPrjAvail) ? 71 : 0);
	if (LstPrjAvail) {
		if ( (LstPrjAlt == !contcontdoc.getElementById("ButPrjExpand")) || (!LstPrjAlt == !contcontdoc.getElementById("ButPrjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagWznmNavProject", "CptPrj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrjCollapse", "icon/collapse"));
		};

		if (!LstPrjAlt == !contcontdoc.getElementById("LstPrj")) {
			mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrj");
			clearElem(mytd);

			if (LstPrjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrj", "./PnlWznmNavProject_LstPrj.xml", true));
			};

		} else {
			if (!LstPrjAlt) refreshLst(contcontdoc.getElementById("LstPrj").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrj",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", "LstPrjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numFLstPrj"))]);
		};

		if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView")) || !contcontdoc.getElementById("ButPrjNewcrd")) {
			if (LstPrjAlt) mytd = contcontdoc.getElementById("dynPrj");
			else mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);

			first = true;

			if (ButPrjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjNewcrd", "icon/newcrd"));
		};

		if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	} else setCtlAvail(contcontdoc, "Prj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ver", LstVerAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ver2", LstVerAvail && !LstVerAlt, (LstVerAvail) ? 71 : 0);
	if (LstVerAvail) {
		if ( (LstVerAlt == !contcontdoc.getElementById("ButVerExpand")) || (!LstVerAlt == !contcontdoc.getElementById("ButVerCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVer");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWznmNavProject", "CptVer")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVerAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVerExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVerCollapse", "icon/collapse"));
		};

		if (!LstVerAlt == !contcontdoc.getElementById("LstVer")) {
			mytd = contcontdoc.getElementById("rdynVer");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVer");
			clearElem(mytd);

			if (LstVerAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVer", "./PnlWznmNavProject_LstVer.xml", true));
			};

		} else {
			if (!LstVerAlt) refreshLst(contcontdoc.getElementById("LstVer").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVer",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", "LstVerNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numFLstVer"))]);
		};

		if ((ButVerViewAvail == !contcontdoc.getElementById("ButVerView")) || !contcontdoc.getElementById("ButVerNewcrd")) {
			if (LstVerAlt) mytd = contcontdoc.getElementById("dynVer");
			else mytd = contcontdoc.getElementById("rdynVer");
			clearElem(mytd);

			first = true;

			if (ButVerViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVerView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVerNewcrd", "icon/newcrd"));
		};

		if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	} else setCtlAvail(contcontdoc, "Ver2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cap", LstCapAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cap2", LstCapAvail && !LstCapAlt, (LstCapAvail) ? 71 : 0);
	if (LstCapAvail) {
		if ( (LstCapAlt == !contcontdoc.getElementById("ButCapExpand")) || (!LstCapAlt == !contcontdoc.getElementById("ButCapCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCap");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCap", retrieveTi(srcdoc, "TagWznmNavProject", "CptCap")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCapAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCapExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCapCollapse", "icon/collapse"));
		};

		if (!LstCapAlt == !contcontdoc.getElementById("LstCap")) {
			mytd = contcontdoc.getElementById("rdynCap");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCap");
			clearElem(mytd);

			if (LstCapAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCap", "./PnlWznmNavProject_LstCap.xml", true));
			};

		} else {
			if (!LstCapAlt) refreshLst(contcontdoc.getElementById("LstCap").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCap",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", "LstCapNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numFLstCap"))]);
		};

		if ((ButCapViewAvail == !contcontdoc.getElementById("ButCapView")) || !contcontdoc.getElementById("ButCapNewcrd")) {
			if (LstCapAlt) mytd = contcontdoc.getElementById("dynCap");
			else mytd = contcontdoc.getElementById("rdynCap");
			clearElem(mytd);

			first = true;

			if (ButCapViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCapView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCapNewcrd", "icon/newcrd"));
		};

		if (ButCapViewAvail) refreshButicon(contcontdoc, "ButCapView", "icon/view", ButCapViewActive, false);
		refreshButicon(contcontdoc, "ButCapNewcrd", "icon/newcrd", ButCapNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cap2", false, 0);

	height -= setCtlAvail(contcontdoc, "Err", LstErrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Err2", LstErrAvail && !LstErrAlt, (LstErrAvail) ? 71 : 0);
	if (LstErrAvail) {
		if ( (LstErrAlt == !contcontdoc.getElementById("ButErrExpand")) || (!LstErrAlt == !contcontdoc.getElementById("ButErrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynErr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptErr", retrieveTi(srcdoc, "TagWznmNavProject", "CptErr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstErrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButErrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButErrCollapse", "icon/collapse"));
		};

		if (!LstErrAlt == !contcontdoc.getElementById("LstErr")) {
			mytd = contcontdoc.getElementById("rdynErr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynErr");
			clearElem(mytd);

			if (LstErrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstErr", "./PnlWznmNavProject_LstErr.xml", true));
			};

		} else {
			if (!LstErrAlt) refreshLst(contcontdoc.getElementById("LstErr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstErr",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", "LstErrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numFLstErr"))]);
		};

		if ((ButErrViewAvail == !contcontdoc.getElementById("ButErrView")) || !contcontdoc.getElementById("ButErrNewcrd")) {
			if (LstErrAlt) mytd = contcontdoc.getElementById("dynErr");
			else mytd = contcontdoc.getElementById("rdynErr");
			clearElem(mytd);

			first = true;

			if (ButErrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButErrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButErrNewcrd", "icon/newcrd"));
		};

		if (ButErrViewAvail) refreshButicon(contcontdoc, "ButErrView", "icon/view", ButErrViewActive, false);
		refreshButicon(contcontdoc, "ButErrNewcrd", "icon/newcrd", ButErrNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Err2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Project", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Project_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Project_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Project_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavProject", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Project_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavProject", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavProject", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavProjectDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavProjectDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavProject", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavProject", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavProject", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavProject", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavProjectData", scrJref, "ContIacWznmNavProject");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavProject", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavProject", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavProject", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavProject", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "ContIacWznmNavProject", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "FeedFLstCap", srcdoc)) mask.push("feedFLstCap");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "FeedFLstErr", srcdoc)) mask.push("feedFLstErr");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "FeedFLstPrj", srcdoc)) mask.push("feedFLstPrj");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "FeedFLstVer", srcdoc)) mask.push("feedFLstVer");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "StatAppWznmNavProject", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "StatShrWznmNavProject", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavProjectData", "TagWznmNavProject", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavProjectData") {
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
			if (blk.nodeName == "DpchEngWznmNavProjectData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Project");
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

			} else if (blk.nodeName == "DpchEngWznmNavProjectData") {
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
