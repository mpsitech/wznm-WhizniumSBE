function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefDetail");
	scrJrefATitle = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefATitle");
	scrJref1NStub = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJref1NStub");
	scrJref1NTablecol = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJref1NTablecol");
	scrJrefTos1NRelation = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefTos1NRelation");
	scrJrefFrs1NRelation = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefFrs1NRelation");
	scrJrefPst1NQuerymod = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefPst1NQuerymod");
	scrJrefAsbMNSubset = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefAsbMNSubset");
	scrJrefBsbMNSubset = retrieveSi(srcdoc, "StatShrWznmSbsRec", "scrJrefBsbMNSubset");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneATitle", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdone1NStub", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdone1NTablecol", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneTos1NRelation", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneFrs1NRelation", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdonePst1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneAsbMNSubset", "false");
	setSi(srcdoc, "StatAppWznmSbsRec", "initdoneBsbMNSubset", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightATitle = 30;
	height1NStub = 30;
	height1NTablecol = 30;
	heightTos1NRelation = 30;
	heightFrs1NRelation = 30;
	heightPst1NQuerymod = 30;
	heightAsbMNSubset = 30;
	heightBsbMNSubset = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmSbsRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneDetail") == "true");
	var initdoneATitle = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneATitle") == "true");
	var initdone1NStub = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdone1NStub") == "true");
	var initdone1NTablecol = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdone1NTablecol") == "true");
	var initdoneTos1NRelation = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneTos1NRelation") == "true");
	var initdoneFrs1NRelation = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneFrs1NRelation") == "true");
	var initdonePst1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdonePst1NQuerymod") == "true");
	var initdoneAsbMNSubset = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneAsbMNSubset") == "true");
	var initdoneBsbMNSubset = (retrieveSi(srcdoc, "StatAppWznmSbsRec", "initdoneBsbMNSubset") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmSbsDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneATitle) {
		lhsdoc.getElementById("ATitle").src = "./PnlWznmSbsATitle.html?scrJref=" + scrJrefATitle;
	} else if (!initdone1NStub) {
		rhsdoc.getElementById("1NStub").src = "./PnlWznmSbs1NStub.html?scrJref=" + scrJref1NStub;
	} else if (!initdone1NTablecol) {
		rhsdoc.getElementById("1NTablecol").src = "./PnlWznmSbs1NTablecol.html?scrJref=" + scrJref1NTablecol;
	} else if (!initdoneTos1NRelation) {
		rhsdoc.getElementById("Tos1NRelation").src = "./PnlWznmSbsTos1NRelation.html?scrJref=" + scrJrefTos1NRelation;
	} else if (!initdoneFrs1NRelation) {
		rhsdoc.getElementById("Frs1NRelation").src = "./PnlWznmSbsFrs1NRelation.html?scrJref=" + scrJrefFrs1NRelation;
	} else if (!initdonePst1NQuerymod) {
		rhsdoc.getElementById("Pst1NQuerymod").src = "./PnlWznmSbsPst1NQuerymod.html?scrJref=" + scrJrefPst1NQuerymod;
	} else if (!initdoneAsbMNSubset) {
		rhsdoc.getElementById("AsbMNSubset").src = "./PnlWznmSbsAsbMNSubset.html?scrJref=" + scrJrefAsbMNSubset;
	} else if (!initdoneBsbMNSubset) {
		rhsdoc.getElementById("BsbMNSubset").src = "./PnlWznmSbsBsbMNSubset.html?scrJref=" + scrJrefBsbMNSubset;

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
		else if (short == "1NStub") height1NStub = height;
		else if (short == "1NTablecol") height1NTablecol = height;
		else if (short == "Tos1NRelation") heightTos1NRelation = height;
		else if (short == "Frs1NRelation") heightFrs1NRelation = height;
		else if (short == "Pst1NQuerymod") heightPst1NQuerymod = height;
		else if (short == "AsbMNSubset") heightAsbMNSubset = height;
		else if (short == "BsbMNSubset") heightBsbMNSubset = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmSbsRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmSbsRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 352);
	doc.getElementById("tdSide").setAttribute("height", "352");
	doc.getElementById("Rec_side").setAttribute("height", "352");
	doc.getElementById("Rec_cont").setAttribute("height", "352");

	doc.getElementById("Rec_side").src = "./PnlWznmSbsRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmSbsRec_b.html";
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
	else if (pnlshort == "1NStub") height1NStub = height;
	else if (pnlshort == "1NTablecol") height1NTablecol = height;
	else if (pnlshort == "Tos1NRelation") heightTos1NRelation = height;
	else if (pnlshort == "Frs1NRelation") heightFrs1NRelation = height;
	else if (pnlshort == "Pst1NQuerymod") heightPst1NQuerymod = height;
	else if (pnlshort == "AsbMNSubset") heightAsbMNSubset = height;
	else if (pnlshort == "BsbMNSubset") heightBsbMNSubset = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightATitle+13 + 5;
	heightRhs = height1NStub+13 + height1NTablecol+13 + heightTos1NRelation+13 + heightFrs1NRelation+13 + heightPst1NQuerymod+13 + heightAsbMNSubset+13 + heightBsbMNSubset+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmSbsRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmSbsRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmSbsRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmSbsRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlpst1nquerymodAvail = (retrieveSi(srcdoc, "StatShrWznmSbsRec", "pnlpst1nquerymodAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmSbsRec", "TxtRef"));

	if (setPnlAvail("Pst1NQuerymod", pnlpst1nquerymodAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmSbsRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmSbsRecData", "ContInfWznmSbsRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmSbsRecData", "StatAppWznmSbsRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmSbsRecData", "StatShrWznmSbsRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmSbsRecData", "TagWznmSbsRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmSbsRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJref1NStub) {
				if (getInitdone("1NStub")) rhsdoc.getElementById("1NStub").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NTablecol) {
				if (getInitdone("1NTablecol")) rhsdoc.getElementById("1NTablecol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTos1NRelation) {
				if (getInitdone("Tos1NRelation")) rhsdoc.getElementById("Tos1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFrs1NRelation) {
				if (getInitdone("Frs1NRelation")) rhsdoc.getElementById("Frs1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefPst1NQuerymod) {
				if (getInitdone("Pst1NQuerymod")) rhsdoc.getElementById("Pst1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAsbMNSubset) {
				if (getInitdone("AsbMNSubset")) rhsdoc.getElementById("AsbMNSubset").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefBsbMNSubset) {
				if (getInitdone("BsbMNSubset")) rhsdoc.getElementById("BsbMNSubset").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmSbsRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmSbsRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmSbsRec", "srefIxWznmVExpstate");

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
