/**
  * \file PnlWznmTcoRec.js
  * web client functionality for panel PnlWznmTcoRec
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJrefDetail");
	scrJrefATitle = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJrefATitle");
	scrJref1NImpexpcol = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJref1NImpexpcol");
	scrJref1NQuerycol = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJref1NQuerycol");
	scrJrefRef1NControl = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJrefRef1NControl");
	scrJrefRef1NQuerymod = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJrefRef1NQuerymod");
	scrJref1NCheck = retrieveSi(srcdoc, "StatShrWznmTcoRec", "scrJref1NCheck");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmTcoRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdoneATitle", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdone1NImpexpcol", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdone1NQuerycol", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdoneRef1NControl", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdoneRef1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmTcoRec", "initdone1NCheck", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightATitle = 30;
	height1NImpexpcol = 30;
	height1NQuerycol = 30;
	heightRef1NControl = 30;
	heightRef1NQuerymod = 30;
	height1NCheck = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmTcoRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneDetail") == "true");
	var initdoneATitle = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneATitle") == "true");
	var initdone1NImpexpcol = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdone1NImpexpcol") == "true");
	var initdone1NQuerycol = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdone1NQuerycol") == "true");
	var initdoneRef1NControl = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneRef1NControl") == "true");
	var initdoneRef1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdoneRef1NQuerymod") == "true");
	var initdone1NCheck = (retrieveSi(srcdoc, "StatAppWznmTcoRec", "initdone1NCheck") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmTcoDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneATitle) {
		lhsdoc.getElementById("ATitle").src = "./PnlWznmTcoATitle.html?scrJref=" + scrJrefATitle;
	} else if (!initdone1NImpexpcol) {
		rhsdoc.getElementById("1NImpexpcol").src = "./PnlWznmTco1NImpexpcol.html?scrJref=" + scrJref1NImpexpcol;
	} else if (!initdone1NQuerycol) {
		rhsdoc.getElementById("1NQuerycol").src = "./PnlWznmTco1NQuerycol.html?scrJref=" + scrJref1NQuerycol;
	} else if (!initdoneRef1NControl) {
		rhsdoc.getElementById("Ref1NControl").src = "./PnlWznmTcoRef1NControl.html?scrJref=" + scrJrefRef1NControl;
	} else if (!initdoneRef1NQuerymod) {
		rhsdoc.getElementById("Ref1NQuerymod").src = "./PnlWznmTcoRef1NQuerymod.html?scrJref=" + scrJrefRef1NQuerymod;
	} else if (!initdone1NCheck) {
		rhsdoc.getElementById("1NCheck").src = "./PnlWznmTco1NCheck.html?scrJref=" + scrJref1NCheck;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "ATitle")) lhsrhsdoc = lhsdoc;
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
		else if (short == "ATitle") heightATitle = height;
		else if (short == "1NImpexpcol") height1NImpexpcol = height;
		else if (short == "1NQuerycol") height1NQuerycol = height;
		else if (short == "Ref1NControl") heightRef1NControl = height;
		else if (short == "Ref1NQuerymod") heightRef1NQuerymod = height;
		else if (short == "1NCheck") height1NCheck = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmTcoRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmTcoRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlWznmTcoRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmTcoRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "ATitle")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "ATitle") heightATitle = height;
	else if (pnlshort == "1NImpexpcol") height1NImpexpcol = height;
	else if (pnlshort == "1NQuerycol") height1NQuerycol = height;
	else if (pnlshort == "Ref1NControl") heightRef1NControl = height;
	else if (pnlshort == "Ref1NQuerymod") heightRef1NQuerymod = height;
	else if (pnlshort == "1NCheck") height1NCheck = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightATitle+13 + 5;
	heightRhs = height1NImpexpcol+13 + height1NQuerycol+13 + heightRef1NControl+13 + heightRef1NQuerymod+13 + height1NCheck+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmTcoRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmTcoRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmTcoRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlatitleAvail = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "pnlatitleAvail") == "true");
	var pnl1nimpexpcolAvail = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "pnl1nimpexpcolAvail") == "true");
	var pnl1nquerycolAvail = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "pnl1nquerycolAvail") == "true");
	var pnlref1ncontrolAvail = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "pnlref1ncontrolAvail") == "true");
	var pnlref1nquerymodAvail = (retrieveSi(srcdoc, "StatShrWznmTcoRec", "pnlref1nquerymodAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmTcoRec", "TxtRef"));

	if (setPnlAvail("ATitle", pnlatitleAvail)) updh = true;
	if (setPnlAvail("1NImpexpcol", pnl1nimpexpcolAvail)) updh = true;
	if (setPnlAvail("1NQuerycol", pnl1nquerycolAvail)) updh = true;
	if (setPnlAvail("Ref1NControl", pnlref1ncontrolAvail)) updh = true;
	if (setPnlAvail("Ref1NQuerymod", pnlref1nquerymodAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTcoRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmTcoRecData", "ContInfWznmTcoRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmTcoRecData", "StatAppWznmTcoRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmTcoRecData", "StatShrWznmTcoRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmTcoRecData", "TagWznmTcoRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmTcoRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefATitle) {
				if (getInitdone("ATitle")) lhsdoc.getElementById("ATitle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NImpexpcol) {
				if (getInitdone("1NImpexpcol")) rhsdoc.getElementById("1NImpexpcol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NQuerycol) {
				if (getInitdone("1NQuerycol")) rhsdoc.getElementById("1NQuerycol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NControl) {
				if (getInitdone("Ref1NControl")) rhsdoc.getElementById("Ref1NControl").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NQuerymod) {
				if (getInitdone("Ref1NQuerymod")) rhsdoc.getElementById("Ref1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NCheck) {
				if (getInitdone("1NCheck")) rhsdoc.getElementById("1NCheck").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmTcoRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmTcoRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTcoRec", "srefIxWznmVExpstate");

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

