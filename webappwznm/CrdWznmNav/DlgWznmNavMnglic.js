/**
  * \file DlgWznmNavMnglic.js
  * web client functionality for dialog DlgWznmNavMnglic
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "Cpt"));

	initCpt(contdoc, "DetHdgSrv", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetHdgSrv"));
	initCpt(contdoc, "DetCptSip", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptSip"));
	initCpt(contdoc, "DetCptScp", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptScp"));
	initBut(contdoc, "DetButScn", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetButScn"));
	initBut(contdoc, "DetButSdc", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetButSdc"));
	initCpt(contdoc, "DetCptFis", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptFis"));
	refreshPup(contdoc, srcdoc, "DetPupFis", "", "FeedFDetPupFis", retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numFDetPupFis"), true, false);
	initCpt(contdoc, "DetCptLcs", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptLcs"));
	initBut(contdoc, "DetButAct", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetButAct"));
	initCpt(contdoc, "DetHdgLic", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetHdgLic"));
	initCpt(contdoc, "DetCptLsr", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptLsr"));
	initCpt(contdoc, "DetCptLar", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptLar"));
	initCpt(contdoc, "DetCptLst", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptLst"));
	initCpt(contdoc, "DetCptLex", retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "DetCptLex"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmNavMnglic", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButActActive = (retrieveSi(srcdoc, "StatShrDlgWznmNavMnglic", "DetButActActive") == "true");

	// IP refresh.vars --- END

	// IP refresh --- BEGIN

	refreshTxt(contdoc, "DetTxtSip", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtSip"));

	refreshTxt(contdoc, "DetTxtScp", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtScp"));

	contdoc.getElementById("DetPupFis").value = retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numFDetPupFis");
	refreshChk(contdoc, "DetChkFis", (retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "DetChkFis") == "true"), true);

	refreshLst(contdoc.getElementById("DetLstLcs").contentWindow.document, srcdoc, 2, true, false, "FeedFDetLstLcs",
				parseInt(retrieveSi(srcdoc, "StatAppDlgWznmNavMnglic", "DetLstLcsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numFDetLstLcs"))]);

	refreshBut(contdoc, "DetButAct", DetButActActive, false);

	refreshTxt(contdoc, "DetTxtLsr", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtLsr"));

	refreshTxt(contdoc, "DetTxtLar", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtLar"));

	refreshTxt(contdoc, "DetTxtLst", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtLst"));

	refreshTxt(contdoc, "DetTxtLex", retrieveCi(srcdoc, "ContInfDlgWznmNavMnglic", "DetTxtLex"));

	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

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
	lstdoc.getElementById("tdLsb").onmousemove = contdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmNavMnglicDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgWznmNavMnglic", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmNavMnglicData", scrJref, "ContIacDlgWznmNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmNavMnglic", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmNavMnglic", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacDlgWznmNavMnglic", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacDlgWznmNavMnglic", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmNavMnglicData", scrJref, "ContIacDlgWznmNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppDlgWznmNavMnglic", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppDlgWznmNavMnglic", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacDlgWznmNavMnglic", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmNavMnglic", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmNavMnglicData", scrJref, "ContIacDlgWznmNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "ContIacDlgWznmNavMnglic", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "ContInfDlgWznmNavMnglic", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "FeedFDetLstLcs", srcdoc)) mask.push("feedFDetLstLcs");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "FeedFDetPupFis", srcdoc)) mask.push("feedFDetPupFis");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "StatAppDlgWznmNavMnglic", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "StatShrDlgWznmNavMnglic", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmNavMnglicData", "TagDlgWznmNavMnglic", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmNavMnglicData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmNavMnglicData") {
		handleDpchEngDlgWznmNavMnglicData(dom);
	};
};

function handleDpchEngDlgWznmNavMnglicData(dom) {
	// IP handleDpchEngDlgWznmNavMnglicData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmNavMnglicData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngWznmAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
							retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
							retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgWznmNavMnglicData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

