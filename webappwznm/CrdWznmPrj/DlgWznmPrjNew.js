// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmPrjNew", "Cpt"));

	initCpt(contdoc, "DetCptSho", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptSho"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptTit"));
	initCpt(contdoc, "DetCptAbt", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptAbt"));
	initCpt(contdoc, "DetCptDty", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptDty"));
	initCpt(contdoc, "DetCptLoc", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptLoc"));
	initCpt(contdoc, "DetCptPlc", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptPlc"));
	initCpt(contdoc, "DetCptTmc", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetCptTmc"));
	initBut(contdoc, "DetButAut", retrieveTi(srcdoc, "TagDlgWznmPrjNew", "DetButAut"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWznmPrjNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWznmPrjNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButAutActive = (retrieveSi(srcdoc, "StatShrDlgWznmPrjNew", "DetButAutActive") == "true");

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWznmPrjNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWznmPrjNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxf(contdoc, "DetTxfSho", "s", retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "DetTxfSho"), true, false, true);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "DetTxfTit"), true, false, true);

	refreshTxft(contdoc, "DetTxfAbt", retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "DetTxfAbt"), true, false, true);

	refreshLst(contdoc.getElementById("DetLstDty").contentWindow.document, srcdoc, 1, true, true, "FeedFDetLstDty",
				parseInt(retrieveSi(srcdoc, "StatAppDlgWznmPrjNew", "DetLstDtyNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numsFDetLstDty")));

	refreshLst(contdoc.getElementById("DetLstLoc").contentWindow.document, srcdoc, 1, true, true, "FeedFDetLstLoc",
				parseInt(retrieveSi(srcdoc, "StatAppDlgWznmPrjNew", "DetLstLocNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numsFDetLstLoc")));

	refreshPup(contdoc, srcdoc, "DetPupPlc", "", "FeedFDetPupPlc", retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numFDetPupPlc"), true, false);

	refreshPup(contdoc, srcdoc, "DetPupPmc", "", "FeedFDetPupPmc", retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numFDetPupPmc"), true, false);

	refreshBut(contdoc, "DetButAut", DetButAutActive, false);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmPrjNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmPrjNew", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmPrjNew", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacDlgWznmPrjNew", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacDlgWznmPrjNew", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmPrjNewData", scrJref, "ContIacDlgWznmPrjNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppDlgWznmPrjNew", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppDlgWznmPrjNew", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacDlgWznmPrjNew", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmPrjNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmPrjNewData", scrJref, "ContIacDlgWznmPrjNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWznmPrjNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmPrjNewData", scrJref, "ContIacDlgWznmPrjNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWznmPrjNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmPrjNewData", scrJref, "ContIacDlgWznmPrjNew");
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

	setCi(srcdoc, "ContIacDlgWznmPrjNew", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmPrjNewData", scrJref, "ContIacDlgWznmPrjNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "ContIacDlgWznmPrjNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "ContInfDlgWznmPrjNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "FeedFDetLstDty", srcdoc)) mask.push("feedFDetLstDty");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "FeedFDetLstLoc", srcdoc)) mask.push("feedFDetLstLoc");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "FeedFDetPupPlc", srcdoc)) mask.push("feedFDetPupPlc");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "FeedFDetPupPmc", srcdoc)) mask.push("feedFDetPupPmc");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "StatAppDlgWznmPrjNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "StatShrDlgWznmPrjNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmPrjNewData", "TagDlgWznmPrjNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmPrjNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmPrjNewData") {
		handleDpchEngDlgWznmPrjNewData(dom);
	};
};

function handleDpchEngDlgWznmPrjNewData(dom) {
	// IP handleDpchEngDlgWznmPrjNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmPrjNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmPrjNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

