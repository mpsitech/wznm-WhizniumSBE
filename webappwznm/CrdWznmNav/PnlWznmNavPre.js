/**
  * \file PnlWznmNavPre.js
  * web client functionality for panel PnlWznmNavPre
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtAppAvail = (retrieveSi(srcdoc, "StatShrWznmNavPre", "TxtAppAvail") == "true"); if (TxtAppAvail) n++;
	var TxtVerAvail = (retrieveSi(srcdoc, "StatShrWznmNavPre", "TxtVerAvail") == "true"); if (TxtVerAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtAppAvail) {
		i++;

		line.appendChild(makeImgBut("ButAppRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWznmNavPre", "CptApp") + ": " + retrieveCi(srcdoc, "ContInfWznmNavPre", "TxtApp")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWznmNavPre", "CptApp") + ": " + retrieveCi(srcdoc, "ContInfWznmNavPre", "TxtApp") + ",\u00a0\u00a0"));
	};

	if (TxtVerAvail) {
		i++;

		line.appendChild(makeImgBut("ButVerRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWznmNavPre", "CptVer") + ": " + retrieveCi(srcdoc, "ContInfWznmNavPre", "TxtVer")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWznmNavPre", "CptVer") + ": " + retrieveCi(srcdoc, "ContInfWznmNavPre", "TxtVer") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavPreData", "ContInfWznmNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmNavPreData", "StatShrWznmNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavPreData", "TagWznmNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavPreData") {
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
			if (blk.nodeName == "DpchEngWznmNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWznmNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

