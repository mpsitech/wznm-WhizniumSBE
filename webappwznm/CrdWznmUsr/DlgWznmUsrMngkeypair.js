// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "Cpt"));

	initCpt(contdoc, "DetCptSte", retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "DetCptSte"));
	setTextContent(contdoc, contdoc.getElementById("DetDld"), retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "DetDld"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButDelAvail = (retrieveSi(srcdoc, "StatShrDlgWznmUsrMngkeypair", "DetButDelAvail") == "true");
	var DetButGenAvail = (retrieveSi(srcdoc, "StatShrDlgWznmUsrMngkeypair", "DetButGenAvail") == "true");
	var ButdelbutgenAvail = (DetButDelAvail || DetButGenAvail);

	var DetDldActive = (retrieveSi(srcdoc, "StatShrDlgWznmUsrMngkeypair", "DetDldActive") == "true");

	var mytd, first;

	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxt(contdoc, "DetTxtSte", retrieveCi(srcdoc, "ContInfDlgWznmUsrMngkeypair", "DetTxtSte"));

	setCtlAvail(contdoc, "Butdelbutgen", ButdelbutgenAvail, 25);
	if (ButdelbutgenAvail) {
		if ((DetButDelAvail == !contdoc.getElementById("DetButDel")) || (DetButGenAvail == !contdoc.getElementById("DetButGen"))) {
			mytd = contdoc.getElementById("dynButdelbutgen");
			clearElem(mytd);

			first = true;

			if (DetButDelAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "DetButDel", retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "DetButDel")));
			};

			if (DetButGenAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "DetButGen", retrieveTi(srcdoc, "TagDlgWznmUsrMngkeypair", "DetButGen")));
			};
		};

	};

	refreshDld(contdoc, "DetDld", scrJref, retrieveCi(srcdoc, "ContInfDlgWznmUsrMngkeypair", "DetDld"), DetDldActive);

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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWznmUsrMngkeypairDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWznmUsrMngkeypairData", "ContInfDlgWznmUsrMngkeypair", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWznmUsrMngkeypairData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWznmUsrMngkeypairData", "StatAppDlgWznmUsrMngkeypair", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWznmUsrMngkeypairData", "StatShrDlgWznmUsrMngkeypair", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWznmUsrMngkeypairData", "TagDlgWznmUsrMngkeypair", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWznmUsrMngkeypairData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWznmUsrMngkeypairData") {
		handleDpchEngDlgWznmUsrMngkeypairData(dom);
	};
};

function handleDpchEngDlgWznmUsrMngkeypairData(dom) {
	// IP handleDpchEngDlgWznmUsrMngkeypairData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWznmUsrMngkeypairData") {
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

			} else if (blk.nodeName == "DpchEngDlgWznmUsrMngkeypairData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
