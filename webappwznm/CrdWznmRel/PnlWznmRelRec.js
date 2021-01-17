function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefDetail");
	scrJrefATitle = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefATitle");
	scrJrefSup1NRelation = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefSup1NRelation");
	scrJref1NTablecol = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJref1NTablecol");
	scrJrefRef1NControl = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefRef1NControl");
	scrJrefRef1NDialog = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefRef1NDialog");
	scrJrefRef1NPanel = retrieveSi(srcdoc, "StatShrWznmRelRec", "scrJrefRef1NPanel");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneATitle", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneSup1NRelation", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdone1NTablecol", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NControl", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NDialog", "false");
	setSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NPanel", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightATitle = 30;
	heightSup1NRelation = 30;
	height1NTablecol = 30;
	heightRef1NControl = 30;
	heightRef1NDialog = 30;
	heightRef1NPanel = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmRelRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmRelRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneDetail") == "true");
	var initdoneATitle = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneATitle") == "true");
	var initdoneSup1NRelation = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneSup1NRelation") == "true");
	var initdone1NTablecol = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdone1NTablecol") == "true");
	var initdoneRef1NControl = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NControl") == "true");
	var initdoneRef1NDialog = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NDialog") == "true");
	var initdoneRef1NPanel = (retrieveSi(srcdoc, "StatAppWznmRelRec", "initdoneRef1NPanel") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmRelDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneATitle) {
		lhsdoc.getElementById("ATitle").src = "./PnlWznmRelATitle.html?scrJref=" + scrJrefATitle;
	} else if (!initdoneSup1NRelation) {
		rhsdoc.getElementById("Sup1NRelation").src = "./PnlWznmRelSup1NRelation.html?scrJref=" + scrJrefSup1NRelation;
	} else if (!initdone1NTablecol) {
		rhsdoc.getElementById("1NTablecol").src = "./PnlWznmRel1NTablecol.html?scrJref=" + scrJref1NTablecol;
	} else if (!initdoneRef1NControl) {
		rhsdoc.getElementById("Ref1NControl").src = "./PnlWznmRelRef1NControl.html?scrJref=" + scrJrefRef1NControl;
	} else if (!initdoneRef1NDialog) {
		rhsdoc.getElementById("Ref1NDialog").src = "./PnlWznmRelRef1NDialog.html?scrJref=" + scrJrefRef1NDialog;
	} else if (!initdoneRef1NPanel) {
		rhsdoc.getElementById("Ref1NPanel").src = "./PnlWznmRelRef1NPanel.html?scrJref=" + scrJrefRef1NPanel;

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
		else if (short == "Sup1NRelation") heightSup1NRelation = height;
		else if (short == "1NTablecol") height1NTablecol = height;
		else if (short == "Ref1NControl") heightRef1NControl = height;
		else if (short == "Ref1NDialog") heightRef1NDialog = height;
		else if (short == "Ref1NPanel") heightRef1NPanel = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmRelRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmRelRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlWznmRelRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmRelRec_b.html";
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
	else if (pnlshort == "Sup1NRelation") heightSup1NRelation = height;
	else if (pnlshort == "1NTablecol") height1NTablecol = height;
	else if (pnlshort == "Ref1NControl") heightRef1NControl = height;
	else if (pnlshort == "Ref1NDialog") heightRef1NDialog = height;
	else if (pnlshort == "Ref1NPanel") heightRef1NPanel = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightATitle+13 + 5;
	heightRhs = heightSup1NRelation+13 + height1NTablecol+13 + heightRef1NControl+13 + heightRef1NDialog+13 + heightRef1NPanel+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmRelRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmRelRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmRelRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmRelRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmRelRec", "TxtRef"));

};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmRelRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmRelRecData", "ContInfWznmRelRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmRelRecData", "StatAppWznmRelRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmRelRecData", "StatShrWznmRelRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmRelRecData", "TagWznmRelRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmRelRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefSup1NRelation) {
				if (getInitdone("Sup1NRelation")) rhsdoc.getElementById("Sup1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NTablecol) {
				if (getInitdone("1NTablecol")) rhsdoc.getElementById("1NTablecol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NControl) {
				if (getInitdone("Ref1NControl")) rhsdoc.getElementById("Ref1NControl").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NDialog) {
				if (getInitdone("Ref1NDialog")) rhsdoc.getElementById("Ref1NDialog").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NPanel) {
				if (getInitdone("Ref1NPanel")) rhsdoc.getElementById("Ref1NPanel").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmRelRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmRelRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmRelRec", "srefIxWznmVExpstate");

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
