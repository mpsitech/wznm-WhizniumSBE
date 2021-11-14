function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefDetail");
	scrJrefAOrder = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefAOrder");
	scrJrefAClause = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefAClause");
	scrJrefSup1NQuery = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefSup1NQuery");
	scrJrefQry1NQuerycol = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefQry1NQuerycol");
	scrJref1NQuerymod = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJref1NQuerymod");
	scrJrefMNTable = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefMNTable");
	scrJrefMNPanel = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefMNPanel");
	scrJrefMNDialog = retrieveSi(srcdoc, "StatShrWznmQryRec", "scrJrefMNDialog");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneAOrder", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneAClause", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneSup1NQuery", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneQry1NQuerycol", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdone1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneMNTable", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneMNPanel", "false");
	setSi(srcdoc, "StatAppWznmQryRec", "initdoneMNDialog", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAOrder = 30;
	heightAClause = 30;
	heightSup1NQuery = 30;
	heightQry1NQuerycol = 30;
	height1NQuerymod = 30;
	heightMNTable = 30;
	heightMNPanel = 30;
	heightMNDialog = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmQryRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmQryRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneDetail") == "true");
	var initdoneAOrder = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneAOrder") == "true");
	var initdoneAClause = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneAClause") == "true");
	var initdoneSup1NQuery = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneSup1NQuery") == "true");
	var initdoneQry1NQuerycol = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneQry1NQuerycol") == "true");
	var initdone1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdone1NQuerymod") == "true");
	var initdoneMNTable = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneMNTable") == "true");
	var initdoneMNPanel = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneMNPanel") == "true");
	var initdoneMNDialog = (retrieveSi(srcdoc, "StatAppWznmQryRec", "initdoneMNDialog") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmQryDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAOrder) {
		lhsdoc.getElementById("AOrder").src = "./PnlWznmQryAOrder.html?scrJref=" + scrJrefAOrder;
	} else if (!initdoneAClause) {
		lhsdoc.getElementById("AClause").src = "./PnlWznmQryAClause.html?scrJref=" + scrJrefAClause;
	} else if (!initdoneSup1NQuery) {
		rhsdoc.getElementById("Sup1NQuery").src = "./PnlWznmQrySup1NQuery.html?scrJref=" + scrJrefSup1NQuery;
	} else if (!initdoneQry1NQuerycol) {
		rhsdoc.getElementById("Qry1NQuerycol").src = "./PnlWznmQryQry1NQuerycol.html?scrJref=" + scrJrefQry1NQuerycol;
	} else if (!initdone1NQuerymod) {
		rhsdoc.getElementById("1NQuerymod").src = "./PnlWznmQry1NQuerymod.html?scrJref=" + scrJref1NQuerymod;
	} else if (!initdoneMNTable) {
		rhsdoc.getElementById("MNTable").src = "./PnlWznmQryMNTable.html?scrJref=" + scrJrefMNTable;
	} else if (!initdoneMNPanel) {
		rhsdoc.getElementById("MNPanel").src = "./PnlWznmQryMNPanel.html?scrJref=" + scrJrefMNPanel;
	} else if (!initdoneMNDialog) {
		rhsdoc.getElementById("MNDialog").src = "./PnlWznmQryMNDialog.html?scrJref=" + scrJrefMNDialog;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AOrder") || (short == "AClause")) lhsrhsdoc = lhsdoc;
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
		else if (short == "AOrder") heightAOrder = height;
		else if (short == "AClause") heightAClause = height;
		else if (short == "Sup1NQuery") heightSup1NQuery = height;
		else if (short == "Qry1NQuerycol") heightQry1NQuerycol = height;
		else if (short == "1NQuerymod") height1NQuerymod = height;
		else if (short == "MNTable") heightMNTable = height;
		else if (short == "MNPanel") heightMNPanel = height;
		else if (short == "MNDialog") heightMNDialog = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmQryRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmQryRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 309);
	doc.getElementById("tdSide").setAttribute("height", "309");
	doc.getElementById("Rec_side").setAttribute("height", "309");
	doc.getElementById("Rec_cont").setAttribute("height", "309");

	doc.getElementById("Rec_side").src = "./PnlWznmQryRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmQryRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AOrder") || (pnlshort == "AClause")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AOrder") heightAOrder = height;
	else if (pnlshort == "AClause") heightAClause = height;
	else if (pnlshort == "Sup1NQuery") heightSup1NQuery = height;
	else if (pnlshort == "Qry1NQuerycol") heightQry1NQuerycol = height;
	else if (pnlshort == "1NQuerymod") height1NQuerymod = height;
	else if (pnlshort == "MNTable") heightMNTable = height;
	else if (pnlshort == "MNPanel") heightMNPanel = height;
	else if (pnlshort == "MNDialog") heightMNDialog = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAOrder+13 + heightAClause+13 + 5;
	heightRhs = heightSup1NQuery+13 + heightQry1NQuerycol+13 + height1NQuerymod+13 + heightMNTable+13 + heightMNPanel+13 + heightMNDialog+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmQryRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmQryRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmQryRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmQryRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmQryRec", "TxtRef"));

};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmQryRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmQryRecData", "ContInfWznmQryRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmQryRecData", "StatAppWznmQryRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmQryRecData", "StatShrWznmQryRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmQryRecData", "TagWznmQryRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmQryRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefAOrder) {
				if (getInitdone("AOrder")) lhsdoc.getElementById("AOrder").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAClause) {
				if (getInitdone("AClause")) lhsdoc.getElementById("AClause").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NQuery) {
				if (getInitdone("Sup1NQuery")) rhsdoc.getElementById("Sup1NQuery").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefQry1NQuerycol) {
				if (getInitdone("Qry1NQuerycol")) rhsdoc.getElementById("Qry1NQuerycol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NQuerymod) {
				if (getInitdone("1NQuerymod")) rhsdoc.getElementById("1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNTable) {
				if (getInitdone("MNTable")) rhsdoc.getElementById("MNTable").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNPanel) {
				if (getInitdone("MNPanel")) rhsdoc.getElementById("MNPanel").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNDialog) {
				if (getInitdone("MNDialog")) rhsdoc.getElementById("MNDialog").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmQryRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmQryRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmQryRec", "srefIxWznmVExpstate");

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
