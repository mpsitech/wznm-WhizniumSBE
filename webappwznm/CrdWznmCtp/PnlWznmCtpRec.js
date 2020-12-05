function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJrefDetail");
	scrJrefKParKey = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJrefKParKey");
	scrJrefKKey = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJrefKKey");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJrefAPar");
	scrJref1NTag = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJref1NTag");
	scrJrefTpl1NCapability = retrieveSi(srcdoc, "StatShrWznmCtpRec", "scrJrefTpl1NCapability");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmCtpRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmCtpRec", "initdoneKParKey", "false");
	setSi(srcdoc, "StatAppWznmCtpRec", "initdoneKKey", "false");
	setSi(srcdoc, "StatAppWznmCtpRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppWznmCtpRec", "initdone1NTag", "false");
	setSi(srcdoc, "StatAppWznmCtpRec", "initdoneTpl1NCapability", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKParKey = 30;
	heightKKey = 30;
	heightAPar = 30;
	height1NTag = 30;
	heightTpl1NCapability = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmCtpRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneDetail") == "true");
	var initdoneKParKey = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneKParKey") == "true");
	var initdoneKKey = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneKKey") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneAPar") == "true");
	var initdone1NTag = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdone1NTag") == "true");
	var initdoneTpl1NCapability = (retrieveSi(srcdoc, "StatAppWznmCtpRec", "initdoneTpl1NCapability") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmCtpDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKParKey) {
		lhsdoc.getElementById("KParKey").src = "./PnlWznmCtpKParKey.html?scrJref=" + scrJrefKParKey;
	} else if (!initdoneKKey) {
		lhsdoc.getElementById("KKey").src = "./PnlWznmCtpKKey.html?scrJref=" + scrJrefKKey;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlWznmCtpAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdone1NTag) {
		rhsdoc.getElementById("1NTag").src = "./PnlWznmCtp1NTag.html?scrJref=" + scrJref1NTag;
	} else if (!initdoneTpl1NCapability) {
		rhsdoc.getElementById("Tpl1NCapability").src = "./PnlWznmCtpTpl1NCapability.html?scrJref=" + scrJrefTpl1NCapability;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KParKey") || (short == "KKey") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KParKey") heightKParKey = height;
		else if (short == "KKey") heightKKey = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "1NTag") height1NTag = height;
		else if (short == "Tpl1NCapability") heightTpl1NCapability = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmCtpRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmCtpRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 223);
	doc.getElementById("tdSide").setAttribute("height", "223");
	doc.getElementById("Rec_side").setAttribute("height", "223");
	doc.getElementById("Rec_cont").setAttribute("height", "223");

	doc.getElementById("Rec_side").src = "./PnlWznmCtpRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmCtpRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KParKey") || (pnlshort == "KKey") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KParKey") heightKParKey = height;
	else if (pnlshort == "KKey") heightKKey = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "1NTag") height1NTag = height;
	else if (pnlshort == "Tpl1NCapability") heightTpl1NCapability = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKParKey+13 + heightKKey+13 + heightAPar+13 + 5;
	heightRhs = height1NTag+13 + heightTpl1NCapability+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmCtpRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmCtpRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmCtpRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmCtpRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmCtpRec", "TxtRef"));

};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmCtpRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmCtpRecData", "ContInfWznmCtpRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmCtpRecData", "StatAppWznmCtpRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmCtpRecData", "StatShrWznmCtpRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmCtpRecData", "TagWznmCtpRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmCtpRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefKParKey) {
				if (getInitdone("KParKey")) lhsdoc.getElementById("KParKey").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKKey) {
				if (getInitdone("KKey")) lhsdoc.getElementById("KKey").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				if (getInitdone("APar")) lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NTag) {
				if (getInitdone("1NTag")) rhsdoc.getElementById("1NTag").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTpl1NCapability) {
				if (getInitdone("Tpl1NCapability")) rhsdoc.getElementById("Tpl1NCapability").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmCtpRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmCtpRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmCtpRec", "srefIxWznmVExpstate");

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

