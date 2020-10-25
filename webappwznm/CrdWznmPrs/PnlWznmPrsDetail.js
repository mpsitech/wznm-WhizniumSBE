/**
  * \file PnlWznmPrsDetail.js
  * web client functionality for panel PnlWznmPrsDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmPrsDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmPrsDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmPrsDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmPrsDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmPrsDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptTit"));
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptFnm"));
	initCpt(contcontdoc, "CptLnm", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptLnm"));
	initCpt(contcontdoc, "CptSex", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptSex"));
	refreshPup(contcontdoc, srcdoc, "PupSex", "", "FeedFPupSex", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numFPupSex"), retrieveSi(srcdoc, "StatShrWznmPrsDetail", "PupSexActive"), false);
	initCpt(contcontdoc, "CptTel", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptTel"));
	initCpt(contcontdoc, "CptEml", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptEml"));
	initCpt(contcontdoc, "CptSal", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptSal"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate");

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

	var height = 313; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxfTitActive") == "true");

	var TxfFnmActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxfFnmActive") == "true");

	var PupJlnActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "PupJlnActive") == "true");
	var ButJlnEditAvail = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "ButJlnEditAvail") == "true");

	var TxtLnmActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxtLnmActive") == "true");

	var LstDrvAlt = (retrieveSi(srcdoc, "StatAppWznmPrsDetail", "LstDrvAlt") == "true");
	var LstDrvActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "LstDrvActive") == "true");

	var PupSexActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "PupSexActive") == "true");

	var TxfTelActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxfTelActive") == "true");

	var TxfEmlActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxfEmlActive") == "true");

	var TxfSalActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "TxfSalActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmPrsDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "s", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "TxfTit"), TxfTitActive, false, true);

	refreshTxf(contcontdoc, "TxfFnm", "s", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "TxfFnm"), TxfFnmActive, false, true);

	if ((ButJlnEditAvail == !contcontdoc.getElementById("ButJlnEdit"))) {
		mytd = contcontdoc.getElementById("rdynJln");
		clearElem(mytd);

		first = true;

		if (ButJlnEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJlnEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJln", "s", "FeedFPupJln", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numFPupJln"), PupJlnActive, false);

	refreshTxt(contcontdoc, "TxtLnm", retrieveCi(srcdoc, "ContInfWznmPrsDetail", "TxtLnm"));

	height -= setCtlAvail(contcontdoc, "Drv2", !LstDrvAlt, 71);
	if ( (LstDrvAlt == !contcontdoc.getElementById("ButDrvExpand")) || (!LstDrvAlt == !contcontdoc.getElementById("ButDrvCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynDrv");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagWznmPrsDetail", "CptDrv")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstDrvAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDrvExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButDrvCollapse", "icon/collapse"));
	};

	if ( (LstDrvAlt == !contcontdoc.getElementById("TxtDrv")) || (!LstDrvAlt == !contcontdoc.getElementById("LstDrv")) ) {
		mytd = contcontdoc.getElementById("dynDrv");
		clearElem(mytd);

		if (LstDrvAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtDrv", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstDrv", "./PnlWznmPrsDetail_LstDrv.xml", false));
		};

	} else {
		if (!LstDrvAlt) refreshLst(contcontdoc.getElementById("LstDrv").contentWindow.document, srcdoc, 1, false, true, "FeedFLstDrv",
					parseInt(retrieveSi(srcdoc, "StatAppWznmPrsDetail", "LstDrvNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numsFLstDrv")));
	};

	if (LstDrvAlt) refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfWznmPrsDetail", "TxtDrv"));

	contcontdoc.getElementById("PupSex").value = retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numFPupSex");

	refreshTxf(contcontdoc, "TxfTel", "", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "TxfTel"), TxfTelActive, false, true);

	refreshTxf(contcontdoc, "TxfEml", "", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "TxfEml"), TxfEmlActive, false, true);

	refreshTxf(contcontdoc, "TxfSal", "", retrieveCi(srcdoc, "ContIacWznmPrsDetail", "TxfSal"), TxfSalActive, false, true);

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
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmPrsDetail", "srefIxWznmVExpstate");

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
	setSi(srcdoc, "StatAppWznmPrsDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmPrsDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmPrsDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmPrsDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmPrsDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmPrsDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmPrsDetailData", scrJref, "ContIacWznmPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmPrsDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmPrsDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmPrsDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmPrsDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmPrsDetailData", scrJref, "ContIacWznmPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmPrsDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmPrsDetailData", scrJref, "ContIacWznmPrsDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmPrsDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmPrsDetailData", scrJref, "ContIacWznmPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "ContIacWznmPrsDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "ContInfWznmPrsDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "FeedFLstDrv", srcdoc)) mask.push("feedFLstDrv");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "FeedFPupJln", srcdoc)) mask.push("feedFPupJln");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "FeedFPupSex", srcdoc)) mask.push("feedFPupSex");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "StatAppWznmPrsDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "StatShrWznmPrsDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmPrsDetailData", "TagWznmPrsDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmPrsDetailData") {
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
			if (blk.nodeName == "DpchEngWznmPrsDetailData") {
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

			} else if (blk.nodeName == "DpchEngWznmPrsDetailData") {
				mergeDpchEngData(dom);
				refresh();
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

