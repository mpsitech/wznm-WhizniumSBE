/**
  * \file PnlWznmConDetail.js
  * web client functionality for panel PnlWznmConDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWznmConDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmConDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWznmConDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWznmConDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmConDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWznmConDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWznmConDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWznmConDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWznmConDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagWznmConDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWznmConDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWznmConDetail", "CptSup"));
	initCpt(contcontdoc, "CptSco", retrieveTi(srcdoc, "TagWznmConDetail", "CptSco"));
	refreshPup(contcontdoc, srcdoc, "PupSco", "", "FeedFPupSco", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupSco"), retrieveSi(srcdoc, "StatShrWznmConDetail", "PupScoActive"), false);
	initCpt(contcontdoc, "CptSty", retrieveTi(srcdoc, "TagWznmConDetail", "CptSty"));
	refreshPup(contcontdoc, srcdoc, "PupSty", "", "FeedFPupSty", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupSty"), retrieveSi(srcdoc, "StatShrWznmConDetail", "PupStyActive"), false);
	initCpt(contcontdoc, "CptSts", retrieveTi(srcdoc, "TagWznmConDetail", "CptSts"));
	initCpt(contcontdoc, "CptShs", retrieveTi(srcdoc, "TagWznmConDetail", "CptShs"));
	initCpt(contcontdoc, "CptAvl", retrieveTi(srcdoc, "TagWznmConDetail", "CptAvl"));
	initCpt(contcontdoc, "CptAct", retrieveTi(srcdoc, "TagWznmConDetail", "CptAct"));
	initCpt(contcontdoc, "CptFedSrf", retrieveTi(srcdoc, "TagWznmConDetail", "CptFedSrf"));
	initCpt(contcontdoc, "CptFedSru", retrieveTi(srcdoc, "TagWznmConDetail", "CptFedSru"));
	refreshPup(contcontdoc, srcdoc, "PupFedSrt", "xs", "FeedFPupFedSrt", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupFedSrt"), true, false);
	initCpt(contcontdoc, "CptFedCmt", retrieveTi(srcdoc, "TagWznmConDetail", "CptFedCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		initA();
	} else if (srefIxWznmVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 1079; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtSrfActive") == "true");

	var PupJtiActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "PupJtiActive") == "true");
	var ButJtiEditAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButJtiEditAvail") == "true");

	var TxtTitActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtTitActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "PupTypActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppWznmConDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButCluUnclusterAvail") == "true");

	var TxtHkuActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtHkuActive") == "true");
	var ButHkuViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButHkuViewAvail") == "true");
	var ButHkuViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButHkuViewActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButReuViewActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButSupViewActive") == "true");

	var PupScoActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "PupScoActive") == "true");

	var PupStyActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "PupStyActive") == "true");

	var LstTagAlt = (retrieveSi(srcdoc, "StatAppWznmConDetail", "LstTagAlt") == "true");
	var TxfTagValid = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfTagValid") == "true");
	var LstTagActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstTagActive") == "true");
	var ButTagViewAvail = !LstTagAlt && (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButTagViewAvail") == "true");;
	var ButTagViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButTagViewActive") == "true");

	var TxtStsActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtStsActive") == "true");
	var ButStsViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButStsViewAvail") == "true");
	var ButStsViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButStsViewActive") == "true");

	var TxtShsActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtShsActive") == "true");
	var ButShsViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButShsViewAvail") == "true");
	var ButShsViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButShsViewActive") == "true");

	var TxfAvlActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfAvlActive") == "true");

	var TxfActActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfActActive") == "true");

	var LstOptAlt = (retrieveSi(srcdoc, "StatAppWznmConDetail", "LstOptAlt") == "true");
	var TxfOptValid = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfOptValid") == "true");
	var LstOptActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstOptActive") == "true");
	var ButOptEditAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButOptEditAvail") == "true");

	var SepFedAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "SepFedAvail") == "true");

	var HdgFedAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "HdgFedAvail") == "true");
	var ButFedNewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedNewAvail") == "true");
	var ButFedDeleteAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedDeleteAvail") == "true");

	var TxtFedSrfAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtFedSrfAvail") == "true");
	var TxtFedSrfActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtFedSrfActive") == "true");

	var TxtFedSruAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtFedSruAvail") == "true");
	var TxtFedSruActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxtFedSruActive") == "true");
	var ButFedSruViewAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedSruViewAvail") == "true");
	var ButFedSruViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedSruViewActive") == "true");

	var LstFedVitAlt = (retrieveSi(srcdoc, "StatAppWznmConDetail", "LstFedVitAlt") == "true");
	var TxfFedVitValid = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfFedVitValid") == "true");
	var LstFedVitAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstFedVitAvail") == "true");
	var LstFedVitActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstFedVitActive") == "true");
	var ButFedVitViewAvail = !LstFedVitAlt && (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedVitViewAvail") == "true");;
	var ButFedVitViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedVitViewActive") == "true");

	var LstFedTagAlt = (retrieveSi(srcdoc, "StatAppWznmConDetail", "LstFedTagAlt") == "true");
	var TxfFedTagValid = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfFedTagValid") == "true");
	var LstFedTagAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstFedTagAvail") == "true");
	var LstFedTagActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "LstFedTagActive") == "true");
	var ButFedTagViewAvail = !LstFedTagAlt && (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedTagViewAvail") == "true");;
	var ButFedTagViewActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButFedTagViewActive") == "true");

	var TxfFedCmtAvail = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfFedCmtAvail") == "true");
	var TxfFedCmtActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "TxfFedCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWznmConDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtSrf"));

	if ((ButJtiEditAvail == !contcontdoc.getElementById("ButJtiEdit"))) {
		mytd = contcontdoc.getElementById("rdynJti");
		clearElem(mytd);

		first = true;

		if (ButJtiEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJtiEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJti", "s", "FeedFPupJti", retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupJti"), PupJtiActive, false);

	refreshTxt(contcontdoc, "TxtTit", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtTit"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupTyp");

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagWznmConDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlWznmConDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

	if ((ButHkuViewAvail == !contcontdoc.getElementById("ButHkuView"))) {
		mytd = contcontdoc.getElementById("rdynHku");
		clearElem(mytd);

		first = true;

		if (ButHkuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHkuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupHkt");

	if (ButHkuViewAvail) refreshButicon(contcontdoc, "ButHkuView", "icon/view", ButHkuViewActive, false);

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

	contcontdoc.getElementById("PupSco").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupSco");

	contcontdoc.getElementById("PupSty").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupSty");

	height -= setCtlAvail(contcontdoc, "Tag2", !LstTagAlt, 71);
	if ( (LstTagAlt == !contcontdoc.getElementById("ButTagExpand")) || (!LstTagAlt == !contcontdoc.getElementById("ButTagCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynTag");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptTag", retrieveTi(srcdoc, "TagWznmConDetail", "CptTag")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstTagAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTagExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButTagCollapse", "icon/collapse"));
	};

	if ( (LstTagAlt == !contcontdoc.getElementById("TxfTag")) || (!LstTagAlt == !contcontdoc.getElementById("LstTag")) ) {
		mytd = contcontdoc.getElementById("dynTag");
		clearElem(mytd);

		if (LstTagAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfTag", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstTag", "./PnlWznmConDetail_LstTag.xml", false));
		};

	} else {
		if (!LstTagAlt) refreshLst(contcontdoc.getElementById("LstTag").contentWindow.document, srcdoc, 1, false, false, "FeedFLstTag",
					parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", "LstTagNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numFLstTag"))]);
	};

	if (LstTagAlt) refreshTxf(contcontdoc, "TxfTag", "", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfTag"), LstTagActive, false, TxfTagValid);

	if ((ButTagViewAvail == !contcontdoc.getElementById("ButTagView"))) {
		mytd = contcontdoc.getElementById("rdynTag");
		clearElem(mytd);

		first = true;

		if (ButTagViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTagView", "icon/view"));
		};
	};

	if (ButTagViewAvail) refreshButicon(contcontdoc, "ButTagView", "icon/view", ButTagViewActive, false);

	if ((ButStsViewAvail == !contcontdoc.getElementById("ButStsView"))) {
		mytd = contcontdoc.getElementById("rdynSts");
		clearElem(mytd);

		first = true;

		if (ButStsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButStsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSts", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtSts"));

	if (ButStsViewAvail) refreshButicon(contcontdoc, "ButStsView", "icon/view", ButStsViewActive, false);

	if ((ButShsViewAvail == !contcontdoc.getElementById("ButShsView"))) {
		mytd = contcontdoc.getElementById("rdynShs");
		clearElem(mytd);

		first = true;

		if (ButShsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButShsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtShs", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtShs"));

	if (ButShsViewAvail) refreshButicon(contcontdoc, "ButShsView", "icon/view", ButShsViewActive, false);

	refreshTxft(contcontdoc, "TxfAvl", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfAvl"), TxfAvlActive, false, true);

	refreshTxft(contcontdoc, "TxfAct", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfAct"), TxfActActive, false, true);

	height -= setCtlAvail(contcontdoc, "Opt2", !LstOptAlt, 71);
	if ( (LstOptAlt == !contcontdoc.getElementById("ButOptExpand")) || (!LstOptAlt == !contcontdoc.getElementById("ButOptCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynOpt");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpt", retrieveTi(srcdoc, "TagWznmConDetail", "CptOpt")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstOptAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOptExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButOptCollapse", "icon/collapse"));
	};

	if ( (LstOptAlt == !contcontdoc.getElementById("TxfOpt")) || (!LstOptAlt == !contcontdoc.getElementById("LstOpt")) ) {
		mytd = contcontdoc.getElementById("dynOpt");
		clearElem(mytd);

		if (LstOptAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfOpt", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstOpt", "./PnlWznmConDetail_LstOpt.xml", false));
		};

	} else {
		if (!LstOptAlt) refreshLst(contcontdoc.getElementById("LstOpt").contentWindow.document, srcdoc, 1, false, true, "FeedFLstOpt",
					parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", "LstOptNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWznmConDetail", "numsFLstOpt")));
	};

	if (LstOptAlt) refreshTxf(contcontdoc, "TxfOpt", "", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfOpt"), LstOptActive, false, TxfOptValid);

	if ((ButOptEditAvail == !contcontdoc.getElementById("ButOptEdit"))) {
		mytd = contcontdoc.getElementById("rdynOpt");
		clearElem(mytd);

		first = true;

		if (ButOptEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOptEdit", "icon/edit"));
		};
	};

	height -= setCtlAvail(contcontdoc, "Fed1", SepFedAvail, 0);
	setCtlAvail(contcontdoc, "Fed2", SepFedAvail, 7);
	setCtlAvail(contcontdoc, "Fed3", SepFedAvail, 0);
	if (SepFedAvail) {

	};

	height -= setCtlAvail(contcontdoc, "Fed", HdgFedAvail, 25);
	if (HdgFedAvail) {
		if ((ButFedNewAvail == !contcontdoc.getElementById("ButFedNew")) || (ButFedDeleteAvail == !contcontdoc.getElementById("ButFedDelete"))) {
			mytd = contcontdoc.getElementById("dynFed");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "HdgFed", retrieveTi(srcdoc, "TagWznmConDetail", "HdgFed")));
			mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

			first = true;

			if (ButFedNewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFedNew", "icon/new"));
			};

			if (ButFedDeleteAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFedDelete", "icon/delete"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "FedSrf", TxtFedSrfAvail, 25);
	if (TxtFedSrfAvail) {
		refreshTxt(contcontdoc, "TxtFedSrf", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtFedSrf"));

	};

	height -= setCtlAvail(contcontdoc, "FedSru", TxtFedSruAvail, 25);
	if (TxtFedSruAvail) {
		if ((ButFedSruViewAvail == !contcontdoc.getElementById("ButFedSruView"))) {
			mytd = contcontdoc.getElementById("rdynFedSru");
			clearElem(mytd);

			first = true;

			if (ButFedSruViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFedSruView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtFedSru", retrieveCi(srcdoc, "ContInfWznmConDetail", "TxtFedSru"));
		contcontdoc.getElementById("PupFedSrt").value = retrieveCi(srcdoc, "ContIacWznmConDetail", "numFPupFedSrt");

		if (ButFedSruViewAvail) refreshButicon(contcontdoc, "ButFedSruView", "icon/view", ButFedSruViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "FedVit", LstFedVitAvail, 96);
	height -= setCtlAvail(contcontdoc, "FedVit2", LstFedVitAvail && !LstFedVitAlt, (LstFedVitAvail) ? 71 : 0);
	if (LstFedVitAvail) {
		if ( (LstFedVitAlt == !contcontdoc.getElementById("ButFedVitExpand")) || (!LstFedVitAlt == !contcontdoc.getElementById("ButFedVitCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFedVit");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFedVit", retrieveTi(srcdoc, "TagWznmConDetail", "CptFedVit")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFedVitAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFedVitExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFedVitCollapse", "icon/collapse"));
		};

		if ( (LstFedVitAlt == !contcontdoc.getElementById("TxfFedVit")) || (!LstFedVitAlt == !contcontdoc.getElementById("LstFedVit")) ) {
			mytd = contcontdoc.getElementById("dynFedVit");
			clearElem(mytd);

			if (LstFedVitAlt) {
				mytd.setAttribute("rowspan", "1");
				mytd.appendChild(makeInputTxf(contcontdoc, "TxfFedVit", ""));
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFedVit", "./PnlWznmConDetail_LstFedVit.xml", false));
			};

		} else {
			if (!LstFedVitAlt) refreshLst(contcontdoc.getElementById("LstFedVit").contentWindow.document, srcdoc, 1, false, false, "FeedFLstFedVit",
						parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", "LstFedVitNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numFLstFedVit"))]);
		};

		if (LstFedVitAlt) refreshTxf(contcontdoc, "TxfFedVit", "", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfFedVit"), LstFedVitActive, false, TxfFedVitValid);

		if ((ButFedVitViewAvail == !contcontdoc.getElementById("ButFedVitView"))) {
			mytd = contcontdoc.getElementById("rdynFedVit");
			clearElem(mytd);

			first = true;

			if (ButFedVitViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFedVitView", "icon/view"));
			};
		};

		if (ButFedVitViewAvail) refreshButicon(contcontdoc, "ButFedVitView", "icon/view", ButFedVitViewActive, false);

	} else setCtlAvail(contcontdoc, "FedVit2", false, 0);

	height -= setCtlAvail(contcontdoc, "FedTag", LstFedTagAvail, 96);
	height -= setCtlAvail(contcontdoc, "FedTag2", LstFedTagAvail && !LstFedTagAlt, (LstFedTagAvail) ? 71 : 0);
	if (LstFedTagAvail) {
		if ( (LstFedTagAlt == !contcontdoc.getElementById("ButFedTagExpand")) || (!LstFedTagAlt == !contcontdoc.getElementById("ButFedTagCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFedTag");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFedTag", retrieveTi(srcdoc, "TagWznmConDetail", "CptFedTag")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFedTagAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFedTagExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFedTagCollapse", "icon/collapse"));
		};

		if ( (LstFedTagAlt == !contcontdoc.getElementById("TxfFedTag")) || (!LstFedTagAlt == !contcontdoc.getElementById("LstFedTag")) ) {
			mytd = contcontdoc.getElementById("dynFedTag");
			clearElem(mytd);

			if (LstFedTagAlt) {
				mytd.setAttribute("rowspan", "1");
				mytd.appendChild(makeInputTxf(contcontdoc, "TxfFedTag", ""));
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFedTag", "./PnlWznmConDetail_LstFedTag.xml", false));
			};

		} else {
			if (!LstFedTagAlt) refreshLst(contcontdoc.getElementById("LstFedTag").contentWindow.document, srcdoc, 1, false, false, "FeedFLstFedTag",
						parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", "LstFedTagNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numFLstFedTag"))]);
		};

		if (LstFedTagAlt) refreshTxf(contcontdoc, "TxfFedTag", "", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfFedTag"), LstFedTagActive, false, TxfFedTagValid);

		if ((ButFedTagViewAvail == !contcontdoc.getElementById("ButFedTagView"))) {
			mytd = contcontdoc.getElementById("rdynFedTag");
			clearElem(mytd);

			first = true;

			if (ButFedTagViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFedTagView", "icon/view"));
			};
		};

		if (ButFedTagViewAvail) refreshButicon(contcontdoc, "ButFedTagView", "icon/view", ButFedTagViewActive, false);

	} else setCtlAvail(contcontdoc, "FedTag2", false, 0);

	height -= setCtlAvail(contcontdoc, "FedCmt", TxfFedCmtAvail, 75);
	if (TxfFedCmtAvail) {
		refreshTxft(contcontdoc, "TxfFedCmt", retrieveCi(srcdoc, "ContIacWznmConDetail", "TxfFedCmt"), TxfFedCmtActive, false, true);

	};

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmConDetail", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		refreshA();
	} else if (srefIxWznmVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWznmVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmConDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmConDetail", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmConDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmConDetail", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWznmConDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmConDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmConDetailData", scrJref, "ContIacWznmConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmConDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmConDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmConDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmConDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWznmConDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmConDetailData", scrJref, "ContIacWznmConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWznmConDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWznmConDetailData", scrJref, "ContIacWznmConDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWznmConDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmConDetailData", scrJref, "ContIacWznmConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWznmConDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmConDetailData", scrJref, "ContIacWznmConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "ContIacWznmConDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "ContInfWznmConDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFLstFedTag", srcdoc)) mask.push("feedFLstFedTag");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFLstFedVit", srcdoc)) mask.push("feedFLstFedVit");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFLstOpt", srcdoc)) mask.push("feedFLstOpt");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFLstTag", srcdoc)) mask.push("feedFLstTag");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupFedSrt", srcdoc)) mask.push("feedFPupFedSrt");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupJti", srcdoc)) mask.push("feedFPupJti");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupSco", srcdoc)) mask.push("feedFPupSco");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupSty", srcdoc)) mask.push("feedFPupSty");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "StatAppWznmConDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "StatShrWznmConDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmConDetailData", "TagWznmConDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmConDetailData") {
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
			if (blk.nodeName == "DpchEngWznmConDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngWznmConDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");
				_scrJref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:scrJref");
				sref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWznmAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));
			};
		};
	};
};

function handleDpchAppDoDlgopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");
				_scrJref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:scrJref");
				sref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:sref");

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

