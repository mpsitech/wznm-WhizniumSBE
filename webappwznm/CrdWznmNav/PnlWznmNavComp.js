// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Comp", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Comp_side").setAttribute("height", "30");
	doc.getElementById("Comp_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Comp_side").src = "./PnlWznmNavComp_aside.html";
	doc.getElementById("Comp_cont").src = "./PnlWznmNavComp_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Comp_side").src = "./PnlWznmNavComp_bside.html";
	doc.getElementById("Comp_cont").src = "./PnlWznmNavComp_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Comp_side").contentDocument;
	contdoc = doc.getElementById("Comp_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavComp", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Comp_side").contentDocument;
	contdoc = doc.getElementById("Comp_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Comp_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Comp_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavComp", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate");

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

	var height = 202; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstOpkAlt = (retrieveSi(srcdoc, "StatAppWznmNavComp", "LstOpkAlt") == "true");
	var LstOpkAvail = (retrieveSi(srcdoc, "StatShrWznmNavComp", "LstOpkAvail") == "true");
	var ButOpkViewAvail = !LstOpkAlt;
	var ButOpkViewActive = (retrieveSi(srcdoc, "StatShrWznmNavComp", "ButOpkViewActive") == "true");
	var ButOpkNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavComp", "ButOpkNewcrdActive") == "true");

	var LstOpxAlt = (retrieveSi(srcdoc, "StatAppWznmNavComp", "LstOpxAlt") == "true");
	var LstOpxAvail = (retrieveSi(srcdoc, "StatShrWznmNavComp", "LstOpxAvail") == "true");
	var ButOpxViewAvail = !LstOpxAlt;
	var ButOpxViewActive = (retrieveSi(srcdoc, "StatShrWznmNavComp", "ButOpxViewActive") == "true");
	var ButOpxNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavComp", "ButOpxNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Opk", LstOpkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Opk2", LstOpkAvail && !LstOpkAlt, (LstOpkAvail) ? 71 : 0);
	if (LstOpkAvail) {
		if ( (LstOpkAlt == !contcontdoc.getElementById("ButOpkExpand")) || (!LstOpkAlt == !contcontdoc.getElementById("ButOpkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynOpk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpk", retrieveTi(srcdoc, "TagWznmNavComp", "CptOpk")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstOpkAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOpkExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButOpkCollapse", "icon/collapse"));
		};

		if (!LstOpkAlt == !contcontdoc.getElementById("LstOpk")) {
			mytd = contcontdoc.getElementById("rdynOpk");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynOpk");
			clearElem(mytd);

			if (LstOpkAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstOpk", "./PnlWznmNavComp_LstOpk.xml", true));
			};

		} else {
			if (!LstOpkAlt) refreshLst(contcontdoc.getElementById("LstOpk").contentWindow.document, srcdoc, 1, true, false, "FeedFLstOpk",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavComp", "LstOpkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavComp", "numFLstOpk"))]);
		};

		if ((ButOpkViewAvail == !contcontdoc.getElementById("ButOpkView")) || !contcontdoc.getElementById("ButOpkNewcrd")) {
			if (LstOpkAlt) mytd = contcontdoc.getElementById("dynOpk");
			else mytd = contcontdoc.getElementById("rdynOpk");
			clearElem(mytd);

			first = true;

			if (ButOpkViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButOpkView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOpkNewcrd", "icon/newcrd"));
		};

		if (ButOpkViewAvail) refreshButicon(contcontdoc, "ButOpkView", "icon/view", ButOpkViewActive, false);
		refreshButicon(contcontdoc, "ButOpkNewcrd", "icon/newcrd", ButOpkNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Opk2", false, 0);

	height -= setCtlAvail(contcontdoc, "Opx", LstOpxAvail, 96);
	height -= setCtlAvail(contcontdoc, "Opx2", LstOpxAvail && !LstOpxAlt, (LstOpxAvail) ? 71 : 0);
	if (LstOpxAvail) {
		if ( (LstOpxAlt == !contcontdoc.getElementById("ButOpxExpand")) || (!LstOpxAlt == !contcontdoc.getElementById("ButOpxCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynOpx");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpx", retrieveTi(srcdoc, "TagWznmNavComp", "CptOpx")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstOpxAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOpxExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButOpxCollapse", "icon/collapse"));
		};

		if (!LstOpxAlt == !contcontdoc.getElementById("LstOpx")) {
			mytd = contcontdoc.getElementById("rdynOpx");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynOpx");
			clearElem(mytd);

			if (LstOpxAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstOpx", "./PnlWznmNavComp_LstOpx.xml", true));
			};

		} else {
			if (!LstOpxAlt) refreshLst(contcontdoc.getElementById("LstOpx").contentWindow.document, srcdoc, 1, true, false, "FeedFLstOpx",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavComp", "LstOpxNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavComp", "numFLstOpx"))]);
		};

		if ((ButOpxViewAvail == !contcontdoc.getElementById("ButOpxView")) || !contcontdoc.getElementById("ButOpxNewcrd")) {
			if (LstOpxAlt) mytd = contcontdoc.getElementById("dynOpx");
			else mytd = contcontdoc.getElementById("rdynOpx");
			clearElem(mytd);

			first = true;

			if (ButOpxViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButOpxView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOpxNewcrd", "icon/newcrd"));
		};

		if (ButOpxViewAvail) refreshButicon(contcontdoc, "ButOpxView", "icon/view", ButOpxViewActive, false);
		refreshButicon(contcontdoc, "ButOpxNewcrd", "icon/newcrd", ButOpxNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Opx2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Comp", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Comp_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Comp_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Comp_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavComp", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Comp_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavComp", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavComp", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavCompDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavCompDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavComp", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavComp", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavComp", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavComp", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavComp", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavComp", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavComp", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavComp", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavCompData", scrJref, "ContIacWznmNavComp");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavComp", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavComp", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavComp", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavComp", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "ContIacWznmNavComp", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "FeedFLstOpk", srcdoc)) mask.push("feedFLstOpk");
	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "FeedFLstOpx", srcdoc)) mask.push("feedFLstOpx");
	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "StatAppWznmNavComp", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "StatShrWznmNavComp", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavCompData", "TagWznmNavComp", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavCompData") {
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
			if (blk.nodeName == "DpchEngWznmNavCompData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Comp");
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

			} else if (blk.nodeName == "DpchEngWznmNavCompData") {
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

