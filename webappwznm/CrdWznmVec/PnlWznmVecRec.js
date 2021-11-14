function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefDetail");
	scrJrefATitle = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefATitle");
	scrJrefVec1NVectoritem = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefVec1NVectoritem");
	scrJrefSrc1NFeed = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefSrc1NFeed");
	scrJrefRef1NPanel = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefRef1NPanel");
	scrJrefFct1NTablecol = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefFct1NTablecol");
	scrJrefPst1NQuerymod = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefPst1NQuerymod");
	scrJrefMNTable = retrieveSi(srcdoc, "StatShrWznmVecRec", "scrJrefMNTable");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneATitle", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneVec1NVectoritem", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneSrc1NFeed", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneRef1NPanel", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneFct1NTablecol", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdonePst1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmVecRec", "initdoneMNTable", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightATitle = 30;
	heightVec1NVectoritem = 30;
	heightSrc1NFeed = 30;
	heightRef1NPanel = 30;
	heightFct1NTablecol = 30;
	heightPst1NQuerymod = 30;
	heightMNTable = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmVecRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmVecRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneDetail") == "true");
	var initdoneATitle = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneATitle") == "true");
	var initdoneVec1NVectoritem = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneVec1NVectoritem") == "true");
	var initdoneSrc1NFeed = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneSrc1NFeed") == "true");
	var initdoneRef1NPanel = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneRef1NPanel") == "true");
	var initdoneFct1NTablecol = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneFct1NTablecol") == "true");
	var initdonePst1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdonePst1NQuerymod") == "true");
	var initdoneMNTable = (retrieveSi(srcdoc, "StatAppWznmVecRec", "initdoneMNTable") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmVecDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneATitle) {
		lhsdoc.getElementById("ATitle").src = "./PnlWznmVecATitle.html?scrJref=" + scrJrefATitle;
	} else if (!initdoneVec1NVectoritem) {
		rhsdoc.getElementById("Vec1NVectoritem").src = "./PnlWznmVecVec1NVectoritem.html?scrJref=" + scrJrefVec1NVectoritem;
	} else if (!initdoneSrc1NFeed) {
		rhsdoc.getElementById("Src1NFeed").src = "./PnlWznmVecSrc1NFeed.html?scrJref=" + scrJrefSrc1NFeed;
	} else if (!initdoneRef1NPanel) {
		rhsdoc.getElementById("Ref1NPanel").src = "./PnlWznmVecRef1NPanel.html?scrJref=" + scrJrefRef1NPanel;
	} else if (!initdoneFct1NTablecol) {
		rhsdoc.getElementById("Fct1NTablecol").src = "./PnlWznmVecFct1NTablecol.html?scrJref=" + scrJrefFct1NTablecol;
	} else if (!initdonePst1NQuerymod) {
		rhsdoc.getElementById("Pst1NQuerymod").src = "./PnlWznmVecPst1NQuerymod.html?scrJref=" + scrJrefPst1NQuerymod;
	} else if (!initdoneMNTable) {
		rhsdoc.getElementById("MNTable").src = "./PnlWznmVecMNTable.html?scrJref=" + scrJrefMNTable;

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
		else if (short == "Vec1NVectoritem") heightVec1NVectoritem = height;
		else if (short == "Src1NFeed") heightSrc1NFeed = height;
		else if (short == "Ref1NPanel") heightRef1NPanel = height;
		else if (short == "Fct1NTablecol") heightFct1NTablecol = height;
		else if (short == "Pst1NQuerymod") heightPst1NQuerymod = height;
		else if (short == "MNTable") heightMNTable = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmVecRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmVecRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 309);
	doc.getElementById("tdSide").setAttribute("height", "309");
	doc.getElementById("Rec_side").setAttribute("height", "309");
	doc.getElementById("Rec_cont").setAttribute("height", "309");

	doc.getElementById("Rec_side").src = "./PnlWznmVecRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmVecRec_b.html";
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
	else if (pnlshort == "Vec1NVectoritem") heightVec1NVectoritem = height;
	else if (pnlshort == "Src1NFeed") heightSrc1NFeed = height;
	else if (pnlshort == "Ref1NPanel") heightRef1NPanel = height;
	else if (pnlshort == "Fct1NTablecol") heightFct1NTablecol = height;
	else if (pnlshort == "Pst1NQuerymod") heightPst1NQuerymod = height;
	else if (pnlshort == "MNTable") heightMNTable = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightATitle+13 + 5;
	heightRhs = heightVec1NVectoritem+13 + heightSrc1NFeed+13 + heightRef1NPanel+13 + heightFct1NTablecol+13 + heightPst1NQuerymod+13 + heightMNTable+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmVecRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmVecRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmVecRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmVecRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlfct1ntablecolAvail = (retrieveSi(srcdoc, "StatShrWznmVecRec", "pnlfct1ntablecolAvail") == "true");
	var pnlpst1nquerymodAvail = (retrieveSi(srcdoc, "StatShrWznmVecRec", "pnlpst1nquerymodAvail") == "true");
	var pnlmntableAvail = (retrieveSi(srcdoc, "StatShrWznmVecRec", "pnlmntableAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmVecRec", "TxtRef"));

	if (setPnlAvail("Fct1NTablecol", pnlfct1ntablecolAvail)) updh = true;
	if (setPnlAvail("Pst1NQuerymod", pnlpst1nquerymodAvail)) updh = true;
	if (setPnlAvail("MNTable", pnlmntableAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVecRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVecRecData", "ContInfWznmVecRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVecRecData", "StatAppWznmVecRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVecRecData", "StatShrWznmVecRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVecRecData", "TagWznmVecRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmVecRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefVec1NVectoritem) {
				if (getInitdone("Vec1NVectoritem")) rhsdoc.getElementById("Vec1NVectoritem").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSrc1NFeed) {
				if (getInitdone("Src1NFeed")) rhsdoc.getElementById("Src1NFeed").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NPanel) {
				if (getInitdone("Ref1NPanel")) rhsdoc.getElementById("Ref1NPanel").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFct1NTablecol) {
				if (getInitdone("Fct1NTablecol")) rhsdoc.getElementById("Fct1NTablecol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefPst1NQuerymod) {
				if (getInitdone("Pst1NQuerymod")) rhsdoc.getElementById("Pst1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNTable) {
				if (getInitdone("MNTable")) rhsdoc.getElementById("MNTable").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmVecRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmVecRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVecRec", "srefIxWznmVExpstate");

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
