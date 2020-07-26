/**
  * \file PnlWznmTblRec.js
  * web client functionality for panel PnlWznmTblRec
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefDetail");
	scrJrefALoadfct = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefALoadfct");
	scrJrefATitle = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefATitle");
	scrJrefTbl1NTablecol = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefTbl1NTablecol");
	scrJref1NImpexp = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJref1NImpexp");
	scrJref1NCheck = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJref1NCheck");
	scrJref1NSubset = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJref1NSubset");
	scrJref1NStub = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJref1NStub");
	scrJrefTo1NRelation = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefTo1NRelation");
	scrJrefFr1NRelation = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefFr1NRelation");
	scrJrefRef1NRtblock = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefRef1NRtblock");
	scrJrefRef1NQuerymod = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefRef1NQuerymod");
	scrJrefFct1NTablecol = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefFct1NTablecol");
	scrJrefHk1NVector = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefHk1NVector");
	scrJrefRef1NCall = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefRef1NCall");
	scrJrefRef1NDialog = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefRef1NDialog");
	scrJrefRef1NPanel = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefRef1NPanel");
	scrJrefSrc1NFeed = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefSrc1NFeed");
	scrJrefPst1NQuerymod = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefPst1NQuerymod");
	scrJrefMNVector = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefMNVector");
	scrJrefMNQuery = retrieveSi(srcdoc, "StatShrWznmTblRec", "scrJrefMNQuery");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneALoadfct", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneATitle", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneTbl1NTablecol", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdone1NImpexp", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdone1NCheck", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdone1NSubset", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdone1NStub", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneTo1NRelation", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneFr1NRelation", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NRtblock", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneFct1NTablecol", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneHk1NVector", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NCall", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NDialog", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NPanel", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneSrc1NFeed", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdonePst1NQuerymod", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneMNVector", "false");
	setSi(srcdoc, "StatAppWznmTblRec", "initdoneMNQuery", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightALoadfct = 30;
	heightATitle = 30;
	heightTbl1NTablecol = 30;
	height1NImpexp = 30;
	height1NCheck = 30;
	height1NSubset = 30;
	height1NStub = 30;
	heightTo1NRelation = 30;
	heightFr1NRelation = 30;
	heightRef1NRtblock = 30;
	heightRef1NQuerymod = 30;
	heightFct1NTablecol = 30;
	heightHk1NVector = 30;
	heightRef1NCall = 30;
	heightRef1NDialog = 30;
	heightRef1NPanel = 30;
	heightSrc1NFeed = 30;
	heightPst1NQuerymod = 30;
	heightMNVector = 30;
	heightMNQuery = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmTblRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneDetail") == "true");
	var initdoneALoadfct = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneALoadfct") == "true");
	var initdoneATitle = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneATitle") == "true");
	var initdoneTbl1NTablecol = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneTbl1NTablecol") == "true");
	var initdone1NImpexp = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone1NImpexp") == "true");
	var initdone1NCheck = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone1NCheck") == "true");
	var initdone1NSubset = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone1NSubset") == "true");
	var initdone1NStub = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdone1NStub") == "true");
	var initdoneTo1NRelation = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneTo1NRelation") == "true");
	var initdoneFr1NRelation = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneFr1NRelation") == "true");
	var initdoneRef1NRtblock = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NRtblock") == "true");
	var initdoneRef1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NQuerymod") == "true");
	var initdoneFct1NTablecol = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneFct1NTablecol") == "true");
	var initdoneHk1NVector = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneHk1NVector") == "true");
	var initdoneRef1NCall = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NCall") == "true");
	var initdoneRef1NDialog = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NDialog") == "true");
	var initdoneRef1NPanel = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneRef1NPanel") == "true");
	var initdoneSrc1NFeed = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneSrc1NFeed") == "true");
	var initdonePst1NQuerymod = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdonePst1NQuerymod") == "true");
	var initdoneMNVector = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneMNVector") == "true");
	var initdoneMNQuery = (retrieveSi(srcdoc, "StatAppWznmTblRec", "initdoneMNQuery") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmTblDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneALoadfct) {
		lhsdoc.getElementById("ALoadfct").src = "./PnlWznmTblALoadfct.html?scrJref=" + scrJrefALoadfct;
	} else if (!initdoneATitle) {
		lhsdoc.getElementById("ATitle").src = "./PnlWznmTblATitle.html?scrJref=" + scrJrefATitle;
	} else if (!initdoneTbl1NTablecol) {
		rhsdoc.getElementById("Tbl1NTablecol").src = "./PnlWznmTblTbl1NTablecol.html?scrJref=" + scrJrefTbl1NTablecol;
	} else if (!initdone1NImpexp) {
		rhsdoc.getElementById("1NImpexp").src = "./PnlWznmTbl1NImpexp.html?scrJref=" + scrJref1NImpexp;
	} else if (!initdone1NCheck) {
		rhsdoc.getElementById("1NCheck").src = "./PnlWznmTbl1NCheck.html?scrJref=" + scrJref1NCheck;
	} else if (!initdone1NSubset) {
		rhsdoc.getElementById("1NSubset").src = "./PnlWznmTbl1NSubset.html?scrJref=" + scrJref1NSubset;
	} else if (!initdone1NStub) {
		rhsdoc.getElementById("1NStub").src = "./PnlWznmTbl1NStub.html?scrJref=" + scrJref1NStub;
	} else if (!initdoneTo1NRelation) {
		rhsdoc.getElementById("To1NRelation").src = "./PnlWznmTblTo1NRelation.html?scrJref=" + scrJrefTo1NRelation;
	} else if (!initdoneFr1NRelation) {
		rhsdoc.getElementById("Fr1NRelation").src = "./PnlWznmTblFr1NRelation.html?scrJref=" + scrJrefFr1NRelation;
	} else if (!initdoneRef1NRtblock) {
		rhsdoc.getElementById("Ref1NRtblock").src = "./PnlWznmTblRef1NRtblock.html?scrJref=" + scrJrefRef1NRtblock;
	} else if (!initdoneRef1NQuerymod) {
		rhsdoc.getElementById("Ref1NQuerymod").src = "./PnlWznmTblRef1NQuerymod.html?scrJref=" + scrJrefRef1NQuerymod;
	} else if (!initdoneFct1NTablecol) {
		rhsdoc.getElementById("Fct1NTablecol").src = "./PnlWznmTblFct1NTablecol.html?scrJref=" + scrJrefFct1NTablecol;
	} else if (!initdoneHk1NVector) {
		rhsdoc.getElementById("Hk1NVector").src = "./PnlWznmTblHk1NVector.html?scrJref=" + scrJrefHk1NVector;
	} else if (!initdoneRef1NCall) {
		rhsdoc.getElementById("Ref1NCall").src = "./PnlWznmTblRef1NCall.html?scrJref=" + scrJrefRef1NCall;
	} else if (!initdoneRef1NDialog) {
		rhsdoc.getElementById("Ref1NDialog").src = "./PnlWznmTblRef1NDialog.html?scrJref=" + scrJrefRef1NDialog;
	} else if (!initdoneRef1NPanel) {
		rhsdoc.getElementById("Ref1NPanel").src = "./PnlWznmTblRef1NPanel.html?scrJref=" + scrJrefRef1NPanel;
	} else if (!initdoneSrc1NFeed) {
		rhsdoc.getElementById("Src1NFeed").src = "./PnlWznmTblSrc1NFeed.html?scrJref=" + scrJrefSrc1NFeed;
	} else if (!initdonePst1NQuerymod) {
		rhsdoc.getElementById("Pst1NQuerymod").src = "./PnlWznmTblPst1NQuerymod.html?scrJref=" + scrJrefPst1NQuerymod;
	} else if (!initdoneMNVector) {
		rhsdoc.getElementById("MNVector").src = "./PnlWznmTblMNVector.html?scrJref=" + scrJrefMNVector;
	} else if (!initdoneMNQuery) {
		rhsdoc.getElementById("MNQuery").src = "./PnlWznmTblMNQuery.html?scrJref=" + scrJrefMNQuery;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "ALoadfct") || (short == "ATitle")) lhsrhsdoc = lhsdoc;
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
		else if (short == "ALoadfct") heightALoadfct = height;
		else if (short == "ATitle") heightATitle = height;
		else if (short == "Tbl1NTablecol") heightTbl1NTablecol = height;
		else if (short == "1NImpexp") height1NImpexp = height;
		else if (short == "1NCheck") height1NCheck = height;
		else if (short == "1NSubset") height1NSubset = height;
		else if (short == "1NStub") height1NStub = height;
		else if (short == "To1NRelation") heightTo1NRelation = height;
		else if (short == "Fr1NRelation") heightFr1NRelation = height;
		else if (short == "Ref1NRtblock") heightRef1NRtblock = height;
		else if (short == "Ref1NQuerymod") heightRef1NQuerymod = height;
		else if (short == "Fct1NTablecol") heightFct1NTablecol = height;
		else if (short == "Hk1NVector") heightHk1NVector = height;
		else if (short == "Ref1NCall") heightRef1NCall = height;
		else if (short == "Ref1NDialog") heightRef1NDialog = height;
		else if (short == "Ref1NPanel") heightRef1NPanel = height;
		else if (short == "Src1NFeed") heightSrc1NFeed = height;
		else if (short == "Pst1NQuerymod") heightPst1NQuerymod = height;
		else if (short == "MNVector") heightMNVector = height;
		else if (short == "MNQuery") heightMNQuery = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmTblRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmTblRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 825);
	doc.getElementById("tdSide").setAttribute("height", "825");
	doc.getElementById("Rec_side").setAttribute("height", "825");
	doc.getElementById("Rec_cont").setAttribute("height", "825");

	doc.getElementById("Rec_side").src = "./PnlWznmTblRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmTblRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "ALoadfct") || (pnlshort == "ATitle")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "ALoadfct") heightALoadfct = height;
	else if (pnlshort == "ATitle") heightATitle = height;
	else if (pnlshort == "Tbl1NTablecol") heightTbl1NTablecol = height;
	else if (pnlshort == "1NImpexp") height1NImpexp = height;
	else if (pnlshort == "1NCheck") height1NCheck = height;
	else if (pnlshort == "1NSubset") height1NSubset = height;
	else if (pnlshort == "1NStub") height1NStub = height;
	else if (pnlshort == "To1NRelation") heightTo1NRelation = height;
	else if (pnlshort == "Fr1NRelation") heightFr1NRelation = height;
	else if (pnlshort == "Ref1NRtblock") heightRef1NRtblock = height;
	else if (pnlshort == "Ref1NQuerymod") heightRef1NQuerymod = height;
	else if (pnlshort == "Fct1NTablecol") heightFct1NTablecol = height;
	else if (pnlshort == "Hk1NVector") heightHk1NVector = height;
	else if (pnlshort == "Ref1NCall") heightRef1NCall = height;
	else if (pnlshort == "Ref1NDialog") heightRef1NDialog = height;
	else if (pnlshort == "Ref1NPanel") heightRef1NPanel = height;
	else if (pnlshort == "Src1NFeed") heightSrc1NFeed = height;
	else if (pnlshort == "Pst1NQuerymod") heightPst1NQuerymod = height;
	else if (pnlshort == "MNVector") heightMNVector = height;
	else if (pnlshort == "MNQuery") heightMNQuery = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightALoadfct+13 + heightATitle+13 + 5;
	heightRhs = heightTbl1NTablecol+13 + height1NImpexp+13 + height1NCheck+13 + height1NSubset+13 + height1NStub+13 + heightTo1NRelation+13 + heightFr1NRelation+13 + heightRef1NRtblock+13 + heightRef1NQuerymod+13 + heightFct1NTablecol+13 + heightHk1NVector+13 + heightRef1NCall+13 + heightRef1NDialog+13 + heightRef1NPanel+13 + heightSrc1NFeed+13 + heightPst1NQuerymod+13 + heightMNVector+13 + heightMNQuery+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmTblRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmTblRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmTblRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmTblRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlaloadfctAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlaloadfctAvail") == "true");
	var pnlatitleAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlatitleAvail") == "true");
	var pnl1nimpexpAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnl1nimpexpAvail") == "true");
	var pnl1ncheckAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnl1ncheckAvail") == "true");
	var pnl1nsubsetAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnl1nsubsetAvail") == "true");
	var pnl1nstubAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnl1nstubAvail") == "true");
	var pnlto1nrelationAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlto1nrelationAvail") == "true");
	var pnlfr1nrelationAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlfr1nrelationAvail") == "true");
	var pnlfct1ntablecolAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlfct1ntablecolAvail") == "true");
	var pnlref1ncallAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlref1ncallAvail") == "true");
	var pnlref1ndialogAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlref1ndialogAvail") == "true");
	var pnlpst1nquerymodAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlpst1nquerymodAvail") == "true");
	var pnlmnvectorAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlmnvectorAvail") == "true");
	var pnlmnqueryAvail = (retrieveSi(srcdoc, "StatShrWznmTblRec", "pnlmnqueryAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmTblRec", "TxtRef"));

	if (setPnlAvail("ALoadfct", pnlaloadfctAvail)) updh = true;
	if (setPnlAvail("ATitle", pnlatitleAvail)) updh = true;
	if (setPnlAvail("1NImpexp", pnl1nimpexpAvail)) updh = true;
	if (setPnlAvail("1NCheck", pnl1ncheckAvail)) updh = true;
	if (setPnlAvail("1NSubset", pnl1nsubsetAvail)) updh = true;
	if (setPnlAvail("1NStub", pnl1nstubAvail)) updh = true;
	if (setPnlAvail("To1NRelation", pnlto1nrelationAvail)) updh = true;
	if (setPnlAvail("Fr1NRelation", pnlfr1nrelationAvail)) updh = true;
	if (setPnlAvail("Fct1NTablecol", pnlfct1ntablecolAvail)) updh = true;
	if (setPnlAvail("Ref1NCall", pnlref1ncallAvail)) updh = true;
	if (setPnlAvail("Ref1NDialog", pnlref1ndialogAvail)) updh = true;
	if (setPnlAvail("Pst1NQuerymod", pnlpst1nquerymodAvail)) updh = true;
	if (setPnlAvail("MNVector", pnlmnvectorAvail)) updh = true;
	if (setPnlAvail("MNQuery", pnlmnqueryAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmTblRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmTblRecData", "ContInfWznmTblRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmTblRecData", "StatAppWznmTblRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmTblRecData", "StatShrWznmTblRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmTblRecData", "TagWznmTblRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmTblRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefALoadfct) {
				if (getInitdone("ALoadfct")) lhsdoc.getElementById("ALoadfct").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefATitle) {
				if (getInitdone("ATitle")) lhsdoc.getElementById("ATitle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTbl1NTablecol) {
				if (getInitdone("Tbl1NTablecol")) rhsdoc.getElementById("Tbl1NTablecol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NImpexp) {
				if (getInitdone("1NImpexp")) rhsdoc.getElementById("1NImpexp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NCheck) {
				if (getInitdone("1NCheck")) rhsdoc.getElementById("1NCheck").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NSubset) {
				if (getInitdone("1NSubset")) rhsdoc.getElementById("1NSubset").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NStub) {
				if (getInitdone("1NStub")) rhsdoc.getElementById("1NStub").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTo1NRelation) {
				if (getInitdone("To1NRelation")) rhsdoc.getElementById("To1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFr1NRelation) {
				if (getInitdone("Fr1NRelation")) rhsdoc.getElementById("Fr1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NRtblock) {
				if (getInitdone("Ref1NRtblock")) rhsdoc.getElementById("Ref1NRtblock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NQuerymod) {
				if (getInitdone("Ref1NQuerymod")) rhsdoc.getElementById("Ref1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFct1NTablecol) {
				if (getInitdone("Fct1NTablecol")) rhsdoc.getElementById("Fct1NTablecol").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVector) {
				if (getInitdone("Hk1NVector")) rhsdoc.getElementById("Hk1NVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NCall) {
				if (getInitdone("Ref1NCall")) rhsdoc.getElementById("Ref1NCall").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NDialog) {
				if (getInitdone("Ref1NDialog")) rhsdoc.getElementById("Ref1NDialog").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NPanel) {
				if (getInitdone("Ref1NPanel")) rhsdoc.getElementById("Ref1NPanel").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSrc1NFeed) {
				if (getInitdone("Src1NFeed")) rhsdoc.getElementById("Src1NFeed").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefPst1NQuerymod) {
				if (getInitdone("Pst1NQuerymod")) rhsdoc.getElementById("Pst1NQuerymod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNVector) {
				if (getInitdone("MNVector")) rhsdoc.getElementById("MNVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNQuery) {
				if (getInitdone("MNQuery")) rhsdoc.getElementById("MNQuery").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmTblRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmTblRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmTblRec", "srefIxWznmVExpstate");

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

