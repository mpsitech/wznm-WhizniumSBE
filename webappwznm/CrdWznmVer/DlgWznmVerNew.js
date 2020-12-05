// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmVerNew", "Cpt"));

	initCpt(contdoc, "DetCptPrj", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptPrj"));
	initCpt(contdoc, "DetCptBvr", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptBvr"));
	initCpt(contdoc, "DetCptVni", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptVni"));
	refreshRbu(contdoc, srcdoc, "DetRbuVni", "FeedFDetRbuVni", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numFDetRbuVni"), true);
	initCpt(contdoc, "DetCptCmt", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptCmt"));
	initCpt(contdoc, "DetCptLoc", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptLoc"));
	initCpt(contdoc, "DetCptPlc", retrieveTi(srcdoc, "TagDlgWznmVerNew", "DetCptPlc"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWznmVerNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWznmVerNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWznmVerNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupPrj", "", "FeedFDetPupPrj", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numFDetPupPrj"), true, false);

	refreshPup(contdoc, srcdoc, "DetPupBvr", "", "FeedFDetPupBvr", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numFDetPupBvr"), true, false);

	setRbuValue(contdoc, "DetRbuVni", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numFDetRbuVni"), true);

	refreshTxft(contdoc, "DetTxfCmt", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "DetTxfCmt"), true, false, true);

	refreshLst(contdoc.getElementById("DetLstLoc").contentWindow.document, srcdoc, 1, true, true, "FeedFDetLstLoc",
				parseInt(retrieveSi(srcdoc, "StatAppDlgWznmVerNew", "DetLstLocNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numsFDetLstLoc")));

	refreshPup(contdoc, srcdoc, "DetPupPlc", "", "FeedFDetPupPlc", retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numFDetPupPlc"), true, false);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmVerNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmVerNew", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWznmVerNew", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacDlgWznmVerNew", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerNewData", scrJref, "ContIacDlgWznmVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppDlgWznmVerNew", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppDlgWznmVerNew", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerNewData", scrJref, "ContIacDlgWznmVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleRbuSelect(_doc, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgWznmVerNew", "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerNewData", scrJref, "ContIacDlgWznmVerNew");
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

	setCi(srcdoc, "ContIacDlgWznmVerNew", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWznmVerNewData", scrJref, "ContIacDlgWznmVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "ContIacDlgWznmVerNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "ContInfDlgWznmVerNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFDetLstLoc", srcdoc)) mask.push("feedFDetLstLoc");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFDetPupBvr", srcdoc)) mask.push("feedFDetPupBvr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFDetPupPlc", srcdoc)) mask.push("feedFDetPupPlc");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFDetPupPrj", srcdoc)) mask.push("feedFDetPupPrj");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFDetRbuVni", srcdoc)) mask.push("feedFDetRbuVni");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "StatAppDlgWznmVerNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "StatShrDlgWznmVerNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmVerNewData", "TagDlgWznmVerNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmVerNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmVerNewData") {
		handleDpchEngDlgWznmVerNewData(dom);
	};
};

function handleDpchEngDlgWznmVerNewData(dom) {
	// IP handleDpchEngDlgWznmVerNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmVerNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmVerNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

