/**
  * \file PnlWznmConRec.js
  * web client functionality for panel PnlWznmConRec
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmConRec", "scrJrefDetail");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrWznmConRec", "scrJrefAPar");
	scrJrefSup1NControl = retrieveSi(srcdoc, "StatShrWznmConRec", "scrJrefSup1NControl");
	scrJrefFedRef1NRtblock = retrieveSi(srcdoc, "StatShrWznmConRec", "scrJrefFedRef1NRtblock");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmConRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmConRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppWznmConRec", "initdoneSup1NControl", "false");
	setSi(srcdoc, "StatAppWznmConRec", "initdoneFedRef1NRtblock", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAPar = 30;
	heightSup1NControl = 30;
	heightFedRef1NRtblock = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmConRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmConRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneAPar") == "true");
	var initdoneSup1NControl = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneSup1NControl") == "true");
	var initdoneFedRef1NRtblock = (retrieveSi(srcdoc, "StatAppWznmConRec", "initdoneFedRef1NRtblock") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmConDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlWznmConAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneSup1NControl) {
		rhsdoc.getElementById("Sup1NControl").src = "./PnlWznmConSup1NControl.html?scrJref=" + scrJrefSup1NControl;
	} else if (!initdoneFedRef1NRtblock) {
		rhsdoc.getElementById("FedRef1NRtblock").src = "./PnlWznmConFedRef1NRtblock.html?scrJref=" + scrJrefFedRef1NRtblock;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Sup1NControl") heightSup1NControl = height;
		else if (short == "FedRef1NRtblock") heightFedRef1NRtblock = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlWznmConRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmConRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlWznmConRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmConRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Sup1NControl") heightSup1NControl = height;
	else if (pnlshort == "FedRef1NRtblock") heightFedRef1NRtblock = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAPar+13 + 5;
	heightRhs = heightSup1NControl+13 + heightFedRef1NRtblock+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmConRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmConRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmConRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmConRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlfedref1nrtblockAvail = (retrieveSi(srcdoc, "StatShrWznmConRec", "pnlfedref1nrtblockAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmConRec", "TxtRef"));

	if (setPnlAvail("FedRef1NRtblock", pnlfedref1nrtblockAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxWznmVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmConRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmConRecData", "ContInfWznmConRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmConRecData", "StatAppWznmConRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmConRecData", "StatShrWznmConRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmConRecData", "TagWznmConRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmConRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

				if (newSrefIxWznmVExpstate != srefIxWznmVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxWznmVExpstate == "mind") {
						minimize();
					} else if (newSrefIxWznmVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxWznmVExpstate != "mind") {
			if (!lhsdoc) return;
			if (!rhsdoc) return;

			if (_scrJref == scrJrefDetail) {
				if (getInitdone("Detail")) lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				if (getInitdone("APar")) lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NControl) {
				if (getInitdone("Sup1NControl")) rhsdoc.getElementById("Sup1NControl").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFedRef1NRtblock) {
				if (getInitdone("FedRef1NRtblock")) rhsdoc.getElementById("FedRef1NRtblock").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWznmConRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWznmConRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmConRec", "srefIxWznmVExpstate");

					if (newSrefIxWznmVExpstate != srefIxWznmVExpstate) {
						updateScrJrefs();

						if (newSrefIxWznmVExpstate == "mind") {
							minimize();
						} else if (newSrefIxWznmVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};

