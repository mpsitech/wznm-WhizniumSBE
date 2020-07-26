/**
  * \file PnlWznmImeDetail.js
  * web client functionality for panel PnlWznmImeDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmImeDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmImeDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmImeDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmImeDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmImeDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmImeDetail", "CptSrf"));
	initCpt(contcontdoc, "CptIex", retrieveTi(srcdoc, "TagWznmImeDetail", "CptIex"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWznmImeDetail", "CptSup"));
	initCpt(contcontdoc, "CptTbl", retrieveTi(srcdoc, "TagWznmImeDetail", "CptTbl"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWznmImeDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate");

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
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxtSrfActive") == "true");

	var TxtIexActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxtIexActive") == "true");
	var ButIexViewAvail = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButIexViewAvail") == "true");
	var ButIexViewActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButIexViewActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButSupViewActive") == "true");

	var TxtTblActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxtTblActive") == "true");

	var LstIopAlt = (retrieveSi(srcdoc, "StatAppWznmImeDetail", "LstIopAlt") == "true");
	var LstIopActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "LstIopActive") == "true");

	var LstRtrAlt = (retrieveSi(srcdoc, "StatAppWznmImeDetail", "LstRtrAlt") == "true");
	var TxfRtrValid = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxfRtrValid") == "true");
	var LstRtrActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "LstRtrActive") == "true");
	var ButRtrViewAvail = !LstRtrAlt && (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButRtrViewAvail") == "true");;
	var ButRtrViewActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButRtrViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmImeDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmImeDetail", "TxtSrf"));

	if ((ButIexViewAvail == !contcontdoc.getElementById("ButIexView"))) {
		mytd = contcontdoc.getElementById("rdynIex");
		clearElem(mytd);

		first = true;

		if (ButIexViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButIexView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtIex", retrieveCi(srcdoc, "ContInfWznmImeDetail", "TxtIex"));

	if (ButIexViewAvail) refreshButicon(contcontdoc, "ButIexView", "icon/view", ButIexViewActive, false);

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWznmImeDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

	refreshTxt(contcontdoc, "TxtTbl", retrieveCi(srcdoc, "ContInfWznmImeDetail", "TxtTbl"));

	height -= setCtlAvail(contcontdoc, "Iop2", !LstIopAlt, 71);
	if ( (LstIopAlt == !contcontdoc.getElementById("ButIopExpand")) || (!LstIopAlt == !contcontdoc.getElementById("ButIopCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynIop");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptIop", retrieveTi(srcdoc, "TagWznmImeDetail", "CptIop")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstIopAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButIopExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButIopCollapse", "icon/collapse"));
	};

	if ( (LstIopAlt == !contcontdoc.getElementById("TxtIop")) || (!LstIopAlt == !contcontdoc.getElementById("LstIop")) ) {
		mytd = contcontdoc.getElementById("dynIop");
		clearElem(mytd);

		if (LstIopAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtIop", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstIop", "./PnlWznmImeDetail_LstIop.xml", false));
		};

	} else {
		if (!LstIopAlt) refreshLst(contcontdoc.getElementById("LstIop").contentWindow.document, srcdoc, 1, false, true, "FeedFLstIop",
					parseInt(retrieveSi(srcdoc, "StatAppWznmImeDetail", "LstIopNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numsFLstIop")));
	};

	if (LstIopAlt) refreshTxt(contcontdoc, "TxtIop", retrieveCi(srcdoc, "ContInfWznmImeDetail", "TxtIop"));

	height -= setCtlAvail(contcontdoc, "Rtr2", !LstRtrAlt, 71);
	if ( (LstRtrAlt == !contcontdoc.getElementById("ButRtrExpand")) || (!LstRtrAlt == !contcontdoc.getElementById("ButRtrCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynRtr");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptRtr", retrieveTi(srcdoc, "TagWznmImeDetail", "CptRtr")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstRtrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRtrExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButRtrCollapse", "icon/collapse"));
	};

	if ( (LstRtrAlt == !contcontdoc.getElementById("TxfRtr")) || (!LstRtrAlt == !contcontdoc.getElementById("LstRtr")) ) {
		mytd = contcontdoc.getElementById("dynRtr");
		clearElem(mytd);

		if (LstRtrAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfRtr", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstRtr", "./PnlWznmImeDetail_LstRtr.xml", false));
		};

	} else {
		if (!LstRtrAlt) refreshLst(contcontdoc.getElementById("LstRtr").contentWindow.document, srcdoc, 1, false, false, "FeedFLstRtr",
					parseInt(retrieveSi(srcdoc, "StatAppWznmImeDetail", "LstRtrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numFLstRtr"))]);
	};

	if (LstRtrAlt) refreshTxf(contcontdoc, "TxfRtr", "", retrieveCi(srcdoc, "ContIacWznmImeDetail", "TxfRtr"), LstRtrActive, false, TxfRtrValid);

	if ((ButRtrViewAvail == !contcontdoc.getElementById("ButRtrView"))) {
		mytd = contcontdoc.getElementById("rdynRtr");
		clearElem(mytd);

		first = true;

		if (ButRtrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRtrView", "icon/view"));
		};
	};

	if (ButRtrViewAvail) refreshButicon(contcontdoc, "ButRtrView", "icon/view", ButRtrViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWznmImeDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmImeDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmImeDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmImeDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmImeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmImeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmImeDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmImeDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmImeDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmImeDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmImeDetailData", scrJref, "ContIacWznmImeDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmImeDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmImeDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmImeDetail", "numF" + ctlsref))]);
	};
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmImeDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmImeDetailData", scrJref, "ContIacWznmImeDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmImeDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmImeDetailData", scrJref, "ContIacWznmImeDetail");
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

	setCi(srcdoc, "ContIacWznmImeDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmImeDetailData", scrJref, "ContIacWznmImeDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "ContIacWznmImeDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "ContInfWznmImeDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "FeedFLstIop", srcdoc)) mask.push("feedFLstIop");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "FeedFLstRtr", srcdoc)) mask.push("feedFLstRtr");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "StatAppWznmImeDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "StatShrWznmImeDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmImeDetailData", "TagWznmImeDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmImeDetailData") {
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
			if (blk.nodeName == "DpchEngWznmImeDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmImeDetailData") {
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

