// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Visual", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Visual_side").setAttribute("height", "30");
	doc.getElementById("Visual_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Visual_side").src = "./PnlWznmNavVisual_aside.html";
	doc.getElementById("Visual_cont").src = "./PnlWznmNavVisual_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Visual_side").src = "./PnlWznmNavVisual_bside.html";
	doc.getElementById("Visual_cont").src = "./PnlWznmNavVisual_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Visual_side").contentDocument;
	contdoc = doc.getElementById("Visual_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavVisual", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Visual_side").contentDocument;
	contdoc = doc.getElementById("Visual_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Visual_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Visual_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavVisual", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate");

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

	var height = 298; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstVisAlt = (retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstVisAlt") == "true");
	var LstVisAvail = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "LstVisAvail") == "true");
	var ButVisViewAvail = !LstVisAlt;
	var ButVisViewActive = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "ButVisViewActive") == "true");

	var LstShtAlt = (retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstShtAlt") == "true");
	var LstShtAvail = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "LstShtAvail") == "true");
	var ButShtViewAvail = !LstShtAlt;
	var ButShtViewActive = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "ButShtViewActive") == "true");
	var ButShtNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "ButShtNewcrdActive") == "true");

	var LstBoxAlt = (retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstBoxAlt") == "true");
	var LstBoxAvail = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "LstBoxAvail") == "true");
	var ButBoxViewAvail = !LstBoxAlt;
	var ButBoxViewActive = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "ButBoxViewActive") == "true");
	var ButBoxNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavVisual", "ButBoxNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Vis", LstVisAvail, 96);
	height -= setCtlAvail(contcontdoc, "Vis2", LstVisAvail && !LstVisAlt, (LstVisAvail) ? 71 : 0);
	if (LstVisAvail) {
		if ( (LstVisAlt == !contcontdoc.getElementById("ButVisExpand")) || (!LstVisAlt == !contcontdoc.getElementById("ButVisCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVis");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVis", retrieveTi(srcdoc, "TagWznmNavVisual", "CptVis")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVisAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVisExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVisCollapse", "icon/collapse"));
		};

		if (!LstVisAlt == !contcontdoc.getElementById("LstVis")) {
			mytd = contcontdoc.getElementById("rdynVis");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVis");
			clearElem(mytd);

			if (LstVisAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVis", "./PnlWznmNavVisual_LstVis.xml", true));
			};

		} else {
			if (!LstVisAlt) refreshLst(contcontdoc.getElementById("LstVis").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVis",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstVisNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numFLstVis"))]);
		};

		if ((ButVisViewAvail == !contcontdoc.getElementById("ButVisView")) || !contcontdoc.getElementById("ButVisNewcrd")) {
			if (LstVisAlt) mytd = contcontdoc.getElementById("dynVis");
			else mytd = contcontdoc.getElementById("rdynVis");
			clearElem(mytd);

			first = true;

			if (ButVisViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVisView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVisNewcrd", "icon/newcrd"));
		};

		if (ButVisViewAvail) refreshButicon(contcontdoc, "ButVisView", "icon/view", ButVisViewActive, false);

	} else setCtlAvail(contcontdoc, "Vis2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sht", LstShtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sht2", LstShtAvail && !LstShtAlt, (LstShtAvail) ? 71 : 0);
	if (LstShtAvail) {
		if ( (LstShtAlt == !contcontdoc.getElementById("ButShtExpand")) || (!LstShtAlt == !contcontdoc.getElementById("ButShtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSht");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSht", retrieveTi(srcdoc, "TagWznmNavVisual", "CptSht")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstShtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButShtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButShtCollapse", "icon/collapse"));
		};

		if (!LstShtAlt == !contcontdoc.getElementById("LstSht")) {
			mytd = contcontdoc.getElementById("rdynSht");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSht");
			clearElem(mytd);

			if (LstShtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSht", "./PnlWznmNavVisual_LstSht.xml", true));
			};

		} else {
			if (!LstShtAlt) refreshLst(contcontdoc.getElementById("LstSht").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSht",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstShtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numFLstSht"))]);
		};

		if ((ButShtViewAvail == !contcontdoc.getElementById("ButShtView")) || !contcontdoc.getElementById("ButShtNewcrd")) {
			if (LstShtAlt) mytd = contcontdoc.getElementById("dynSht");
			else mytd = contcontdoc.getElementById("rdynSht");
			clearElem(mytd);

			first = true;

			if (ButShtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButShtView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButShtNewcrd", "icon/newcrd"));
		};

		if (ButShtViewAvail) refreshButicon(contcontdoc, "ButShtView", "icon/view", ButShtViewActive, false);
		refreshButicon(contcontdoc, "ButShtNewcrd", "icon/newcrd", ButShtNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sht2", false, 0);

	height -= setCtlAvail(contcontdoc, "Box", LstBoxAvail, 96);
	height -= setCtlAvail(contcontdoc, "Box2", LstBoxAvail && !LstBoxAlt, (LstBoxAvail) ? 71 : 0);
	if (LstBoxAvail) {
		if ( (LstBoxAlt == !contcontdoc.getElementById("ButBoxExpand")) || (!LstBoxAlt == !contcontdoc.getElementById("ButBoxCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynBox");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptBox", retrieveTi(srcdoc, "TagWznmNavVisual", "CptBox")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstBoxAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButBoxExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButBoxCollapse", "icon/collapse"));
		};

		if (!LstBoxAlt == !contcontdoc.getElementById("LstBox")) {
			mytd = contcontdoc.getElementById("rdynBox");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynBox");
			clearElem(mytd);

			if (LstBoxAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstBox", "./PnlWznmNavVisual_LstBox.xml", true));
			};

		} else {
			if (!LstBoxAlt) refreshLst(contcontdoc.getElementById("LstBox").contentWindow.document, srcdoc, 1, true, false, "FeedFLstBox",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", "LstBoxNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numFLstBox"))]);
		};

		if ((ButBoxViewAvail == !contcontdoc.getElementById("ButBoxView")) || !contcontdoc.getElementById("ButBoxNewcrd")) {
			if (LstBoxAlt) mytd = contcontdoc.getElementById("dynBox");
			else mytd = contcontdoc.getElementById("rdynBox");
			clearElem(mytd);

			first = true;

			if (ButBoxViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButBoxView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBoxNewcrd", "icon/newcrd"));
		};

		if (ButBoxViewAvail) refreshButicon(contcontdoc, "ButBoxView", "icon/view", ButBoxViewActive, false);
		refreshButicon(contcontdoc, "ButBoxNewcrd", "icon/newcrd", ButBoxNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Box2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Visual", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Visual_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Visual_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Visual_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavVisual", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Visual_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavVisual", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavVisual", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavVisualDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavVisualDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavVisual", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavVisual", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavVisualData", scrJref, "ContIacWznmNavVisual");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavVisual", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavVisual", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavVisual", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "ContIacWznmNavVisual", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "FeedFLstBox", srcdoc)) mask.push("feedFLstBox");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "FeedFLstSht", srcdoc)) mask.push("feedFLstSht");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "FeedFLstVis", srcdoc)) mask.push("feedFLstVis");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "StatAppWznmNavVisual", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "StatShrWznmNavVisual", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavVisualData", "TagWznmNavVisual", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavVisualData") {
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
			if (blk.nodeName == "DpchEngWznmNavVisualData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Visual");
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

			} else if (blk.nodeName == "DpchEngWznmNavVisualData") {
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
