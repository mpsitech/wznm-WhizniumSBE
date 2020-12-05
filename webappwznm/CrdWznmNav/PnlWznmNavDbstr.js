// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Dbstr", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Dbstr_side").setAttribute("height", "30");
	doc.getElementById("Dbstr_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Dbstr_side").src = "./PnlWznmNavDbstr_aside.html";
	doc.getElementById("Dbstr_cont").src = "./PnlWznmNavDbstr_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Dbstr_side").src = "./PnlWznmNavDbstr_bside.html";
	doc.getElementById("Dbstr_cont").src = "./PnlWznmNavDbstr_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Dbstr_side").contentDocument;
	contdoc = doc.getElementById("Dbstr_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavDbstr", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Dbstr_side").contentDocument;
	contdoc = doc.getElementById("Dbstr_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Dbstr_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Dbstr_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavDbstr", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate");

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

	var height = 1066; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstTblAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstTblAlt") == "true");
	var LstTblAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstTblAvail") == "true");
	var ButTblViewAvail = !LstTblAlt;
	var ButTblViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButTblViewActive") == "true");
	var ButTblNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButTblNewcrdActive") == "true");

	var LstTcoAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstTcoAlt") == "true");
	var LstTcoAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstTcoAvail") == "true");
	var ButTcoViewAvail = !LstTcoAlt;
	var ButTcoViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButTcoViewActive") == "true");
	var ButTcoNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButTcoNewcrdActive") == "true");

	var LstSbsAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstSbsAlt") == "true");
	var LstSbsAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstSbsAvail") == "true");
	var ButSbsViewAvail = !LstSbsAlt;
	var ButSbsViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButSbsViewActive") == "true");
	var ButSbsNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButSbsNewcrdActive") == "true");

	var LstRelAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstRelAlt") == "true");
	var LstRelAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstRelAvail") == "true");
	var ButRelViewAvail = !LstRelAlt;
	var ButRelViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButRelViewActive") == "true");
	var ButRelNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButRelNewcrdActive") == "true");

	var LstVecAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstVecAlt") == "true");
	var LstVecAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstVecAvail") == "true");
	var ButVecViewAvail = !LstVecAlt;
	var ButVecViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButVecViewActive") == "true");
	var ButVecNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButVecNewcrdActive") == "true");

	var LstVitAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstVitAlt") == "true");
	var LstVitAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstVitAvail") == "true");
	var ButVitViewAvail = !LstVitAlt;
	var ButVitViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButVitViewActive") == "true");
	var ButVitNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButVitNewcrdActive") == "true");

	var LstChkAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstChkAlt") == "true");
	var LstChkAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstChkAvail") == "true");
	var ButChkViewAvail = !LstChkAlt;
	var ButChkViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButChkViewActive") == "true");
	var ButChkNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButChkNewcrdActive") == "true");

	var LstStbAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstStbAlt") == "true");
	var LstStbAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstStbAvail") == "true");
	var ButStbViewAvail = !LstStbAlt;
	var ButStbViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButStbViewActive") == "true");
	var ButStbNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButStbNewcrdActive") == "true");

	var LstIexAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstIexAlt") == "true");
	var LstIexAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstIexAvail") == "true");
	var ButIexViewAvail = !LstIexAlt;
	var ButIexViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButIexViewActive") == "true");
	var ButIexNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButIexNewcrdActive") == "true");

	var LstImeAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstImeAlt") == "true");
	var LstImeAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstImeAvail") == "true");
	var ButImeViewAvail = !LstImeAlt;
	var ButImeViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButImeViewActive") == "true");
	var ButImeNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButImeNewcrdActive") == "true");

	var LstIelAlt = (retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstIelAlt") == "true");
	var LstIelAvail = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "LstIelAvail") == "true");
	var ButIelViewAvail = !LstIelAlt;
	var ButIelViewActive = (retrieveSi(srcdoc, "StatShrWznmNavDbstr", "ButIelViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Tbl", LstTblAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tbl2", LstTblAvail && !LstTblAlt, (LstTblAvail) ? 71 : 0);
	if (LstTblAvail) {
		if ( (LstTblAlt == !contcontdoc.getElementById("ButTblExpand")) || (!LstTblAlt == !contcontdoc.getElementById("ButTblCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTbl");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTbl", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptTbl")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTblAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTblExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTblCollapse", "icon/collapse"));
		};

		if (!LstTblAlt == !contcontdoc.getElementById("LstTbl")) {
			mytd = contcontdoc.getElementById("rdynTbl");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTbl");
			clearElem(mytd);

			if (LstTblAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTbl", "./PnlWznmNavDbstr_LstTbl.xml", true));
			};

		} else {
			if (!LstTblAlt) refreshLst(contcontdoc.getElementById("LstTbl").contentWindow.document, srcdoc, 1, true, false, "FeedFLstTbl",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstTblNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstTbl"))]);
		};

		if ((ButTblViewAvail == !contcontdoc.getElementById("ButTblView")) || !contcontdoc.getElementById("ButTblNewcrd")) {
			if (LstTblAlt) mytd = contcontdoc.getElementById("dynTbl");
			else mytd = contcontdoc.getElementById("rdynTbl");
			clearElem(mytd);

			first = true;

			if (ButTblViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTblView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTblNewcrd", "icon/newcrd"));
		};

		if (ButTblViewAvail) refreshButicon(contcontdoc, "ButTblView", "icon/view", ButTblViewActive, false);
		refreshButicon(contcontdoc, "ButTblNewcrd", "icon/newcrd", ButTblNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Tbl2", false, 0);

	height -= setCtlAvail(contcontdoc, "Tco", LstTcoAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tco2", LstTcoAvail && !LstTcoAlt, (LstTcoAvail) ? 71 : 0);
	if (LstTcoAvail) {
		if ( (LstTcoAlt == !contcontdoc.getElementById("ButTcoExpand")) || (!LstTcoAlt == !contcontdoc.getElementById("ButTcoCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTco");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTco", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptTco")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTcoAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTcoExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTcoCollapse", "icon/collapse"));
		};

		if (!LstTcoAlt == !contcontdoc.getElementById("LstTco")) {
			mytd = contcontdoc.getElementById("rdynTco");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTco");
			clearElem(mytd);

			if (LstTcoAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTco", "./PnlWznmNavDbstr_LstTco.xml", true));
			};

		} else {
			if (!LstTcoAlt) refreshLst(contcontdoc.getElementById("LstTco").contentWindow.document, srcdoc, 1, true, false, "FeedFLstTco",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstTcoNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstTco"))]);
		};

		if ((ButTcoViewAvail == !contcontdoc.getElementById("ButTcoView")) || !contcontdoc.getElementById("ButTcoNewcrd")) {
			if (LstTcoAlt) mytd = contcontdoc.getElementById("dynTco");
			else mytd = contcontdoc.getElementById("rdynTco");
			clearElem(mytd);

			first = true;

			if (ButTcoViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTcoView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTcoNewcrd", "icon/newcrd"));
		};

		if (ButTcoViewAvail) refreshButicon(contcontdoc, "ButTcoView", "icon/view", ButTcoViewActive, false);
		refreshButicon(contcontdoc, "ButTcoNewcrd", "icon/newcrd", ButTcoNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Tco2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sbs", LstSbsAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sbs2", LstSbsAvail && !LstSbsAlt, (LstSbsAvail) ? 71 : 0);
	if (LstSbsAvail) {
		if ( (LstSbsAlt == !contcontdoc.getElementById("ButSbsExpand")) || (!LstSbsAlt == !contcontdoc.getElementById("ButSbsCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSbs");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSbs", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptSbs")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSbsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSbsExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSbsCollapse", "icon/collapse"));
		};

		if (!LstSbsAlt == !contcontdoc.getElementById("LstSbs")) {
			mytd = contcontdoc.getElementById("rdynSbs");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSbs");
			clearElem(mytd);

			if (LstSbsAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSbs", "./PnlWznmNavDbstr_LstSbs.xml", true));
			};

		} else {
			if (!LstSbsAlt) refreshLst(contcontdoc.getElementById("LstSbs").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSbs",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstSbsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstSbs"))]);
		};

		if ((ButSbsViewAvail == !contcontdoc.getElementById("ButSbsView")) || !contcontdoc.getElementById("ButSbsNewcrd")) {
			if (LstSbsAlt) mytd = contcontdoc.getElementById("dynSbs");
			else mytd = contcontdoc.getElementById("rdynSbs");
			clearElem(mytd);

			first = true;

			if (ButSbsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSbsView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSbsNewcrd", "icon/newcrd"));
		};

		if (ButSbsViewAvail) refreshButicon(contcontdoc, "ButSbsView", "icon/view", ButSbsViewActive, false);
		refreshButicon(contcontdoc, "ButSbsNewcrd", "icon/newcrd", ButSbsNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sbs2", false, 0);

	height -= setCtlAvail(contcontdoc, "Rel", LstRelAvail, 96);
	height -= setCtlAvail(contcontdoc, "Rel2", LstRelAvail && !LstRelAlt, (LstRelAvail) ? 71 : 0);
	if (LstRelAvail) {
		if ( (LstRelAlt == !contcontdoc.getElementById("ButRelExpand")) || (!LstRelAlt == !contcontdoc.getElementById("ButRelCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRel");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRel", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptRel")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRelAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRelExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRelCollapse", "icon/collapse"));
		};

		if (!LstRelAlt == !contcontdoc.getElementById("LstRel")) {
			mytd = contcontdoc.getElementById("rdynRel");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRel");
			clearElem(mytd);

			if (LstRelAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRel", "./PnlWznmNavDbstr_LstRel.xml", true));
			};

		} else {
			if (!LstRelAlt) refreshLst(contcontdoc.getElementById("LstRel").contentWindow.document, srcdoc, 1, true, false, "FeedFLstRel",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstRelNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstRel"))]);
		};

		if ((ButRelViewAvail == !contcontdoc.getElementById("ButRelView")) || !contcontdoc.getElementById("ButRelNewcrd")) {
			if (LstRelAlt) mytd = contcontdoc.getElementById("dynRel");
			else mytd = contcontdoc.getElementById("rdynRel");
			clearElem(mytd);

			first = true;

			if (ButRelViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRelView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRelNewcrd", "icon/newcrd"));
		};

		if (ButRelViewAvail) refreshButicon(contcontdoc, "ButRelView", "icon/view", ButRelViewActive, false);
		refreshButicon(contcontdoc, "ButRelNewcrd", "icon/newcrd", ButRelNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Rel2", false, 0);

	height -= setCtlAvail(contcontdoc, "Vec", LstVecAvail, 96);
	height -= setCtlAvail(contcontdoc, "Vec2", LstVecAvail && !LstVecAlt, (LstVecAvail) ? 71 : 0);
	if (LstVecAvail) {
		if ( (LstVecAlt == !contcontdoc.getElementById("ButVecExpand")) || (!LstVecAlt == !contcontdoc.getElementById("ButVecCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVec");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVec", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptVec")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVecAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVecExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVecCollapse", "icon/collapse"));
		};

		if (!LstVecAlt == !contcontdoc.getElementById("LstVec")) {
			mytd = contcontdoc.getElementById("rdynVec");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVec");
			clearElem(mytd);

			if (LstVecAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVec", "./PnlWznmNavDbstr_LstVec.xml", true));
			};

		} else {
			if (!LstVecAlt) refreshLst(contcontdoc.getElementById("LstVec").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVec",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstVecNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstVec"))]);
		};

		if ((ButVecViewAvail == !contcontdoc.getElementById("ButVecView")) || !contcontdoc.getElementById("ButVecNewcrd")) {
			if (LstVecAlt) mytd = contcontdoc.getElementById("dynVec");
			else mytd = contcontdoc.getElementById("rdynVec");
			clearElem(mytd);

			first = true;

			if (ButVecViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVecView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVecNewcrd", "icon/newcrd"));
		};

		if (ButVecViewAvail) refreshButicon(contcontdoc, "ButVecView", "icon/view", ButVecViewActive, false);
		refreshButicon(contcontdoc, "ButVecNewcrd", "icon/newcrd", ButVecNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Vec2", false, 0);

	height -= setCtlAvail(contcontdoc, "Vit", LstVitAvail, 96);
	height -= setCtlAvail(contcontdoc, "Vit2", LstVitAvail && !LstVitAlt, (LstVitAvail) ? 71 : 0);
	if (LstVitAvail) {
		if ( (LstVitAlt == !contcontdoc.getElementById("ButVitExpand")) || (!LstVitAlt == !contcontdoc.getElementById("ButVitCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVit");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVit", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptVit")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVitAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVitExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVitCollapse", "icon/collapse"));
		};

		if (!LstVitAlt == !contcontdoc.getElementById("LstVit")) {
			mytd = contcontdoc.getElementById("rdynVit");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVit");
			clearElem(mytd);

			if (LstVitAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVit", "./PnlWznmNavDbstr_LstVit.xml", true));
			};

		} else {
			if (!LstVitAlt) refreshLst(contcontdoc.getElementById("LstVit").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVit",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstVitNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstVit"))]);
		};

		if ((ButVitViewAvail == !contcontdoc.getElementById("ButVitView")) || !contcontdoc.getElementById("ButVitNewcrd")) {
			if (LstVitAlt) mytd = contcontdoc.getElementById("dynVit");
			else mytd = contcontdoc.getElementById("rdynVit");
			clearElem(mytd);

			first = true;

			if (ButVitViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVitView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVitNewcrd", "icon/newcrd"));
		};

		if (ButVitViewAvail) refreshButicon(contcontdoc, "ButVitView", "icon/view", ButVitViewActive, false);
		refreshButicon(contcontdoc, "ButVitNewcrd", "icon/newcrd", ButVitNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Vit2", false, 0);

	height -= setCtlAvail(contcontdoc, "Chk", LstChkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Chk2", LstChkAvail && !LstChkAlt, (LstChkAvail) ? 71 : 0);
	if (LstChkAvail) {
		if ( (LstChkAlt == !contcontdoc.getElementById("ButChkExpand")) || (!LstChkAlt == !contcontdoc.getElementById("ButChkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynChk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptChk", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptChk")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstChkAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButChkExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButChkCollapse", "icon/collapse"));
		};

		if (!LstChkAlt == !contcontdoc.getElementById("LstChk")) {
			mytd = contcontdoc.getElementById("rdynChk");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynChk");
			clearElem(mytd);

			if (LstChkAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstChk", "./PnlWznmNavDbstr_LstChk.xml", true));
			};

		} else {
			if (!LstChkAlt) refreshLst(contcontdoc.getElementById("LstChk").contentWindow.document, srcdoc, 1, true, false, "FeedFLstChk",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstChkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstChk"))]);
		};

		if ((ButChkViewAvail == !contcontdoc.getElementById("ButChkView")) || !contcontdoc.getElementById("ButChkNewcrd")) {
			if (LstChkAlt) mytd = contcontdoc.getElementById("dynChk");
			else mytd = contcontdoc.getElementById("rdynChk");
			clearElem(mytd);

			first = true;

			if (ButChkViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButChkView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButChkNewcrd", "icon/newcrd"));
		};

		if (ButChkViewAvail) refreshButicon(contcontdoc, "ButChkView", "icon/view", ButChkViewActive, false);
		refreshButicon(contcontdoc, "ButChkNewcrd", "icon/newcrd", ButChkNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Chk2", false, 0);

	height -= setCtlAvail(contcontdoc, "Stb", LstStbAvail, 96);
	height -= setCtlAvail(contcontdoc, "Stb2", LstStbAvail && !LstStbAlt, (LstStbAvail) ? 71 : 0);
	if (LstStbAvail) {
		if ( (LstStbAlt == !contcontdoc.getElementById("ButStbExpand")) || (!LstStbAlt == !contcontdoc.getElementById("ButStbCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynStb");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptStb", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptStb")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstStbAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButStbExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButStbCollapse", "icon/collapse"));
		};

		if (!LstStbAlt == !contcontdoc.getElementById("LstStb")) {
			mytd = contcontdoc.getElementById("rdynStb");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynStb");
			clearElem(mytd);

			if (LstStbAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstStb", "./PnlWznmNavDbstr_LstStb.xml", true));
			};

		} else {
			if (!LstStbAlt) refreshLst(contcontdoc.getElementById("LstStb").contentWindow.document, srcdoc, 1, true, false, "FeedFLstStb",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstStbNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstStb"))]);
		};

		if ((ButStbViewAvail == !contcontdoc.getElementById("ButStbView")) || !contcontdoc.getElementById("ButStbNewcrd")) {
			if (LstStbAlt) mytd = contcontdoc.getElementById("dynStb");
			else mytd = contcontdoc.getElementById("rdynStb");
			clearElem(mytd);

			first = true;

			if (ButStbViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButStbView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButStbNewcrd", "icon/newcrd"));
		};

		if (ButStbViewAvail) refreshButicon(contcontdoc, "ButStbView", "icon/view", ButStbViewActive, false);
		refreshButicon(contcontdoc, "ButStbNewcrd", "icon/newcrd", ButStbNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Stb2", false, 0);

	height -= setCtlAvail(contcontdoc, "Iex", LstIexAvail, 96);
	height -= setCtlAvail(contcontdoc, "Iex2", LstIexAvail && !LstIexAlt, (LstIexAvail) ? 71 : 0);
	if (LstIexAvail) {
		if ( (LstIexAlt == !contcontdoc.getElementById("ButIexExpand")) || (!LstIexAlt == !contcontdoc.getElementById("ButIexCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynIex");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptIex", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptIex")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstIexAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButIexExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButIexCollapse", "icon/collapse"));
		};

		if (!LstIexAlt == !contcontdoc.getElementById("LstIex")) {
			mytd = contcontdoc.getElementById("rdynIex");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynIex");
			clearElem(mytd);

			if (LstIexAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstIex", "./PnlWznmNavDbstr_LstIex.xml", true));
			};

		} else {
			if (!LstIexAlt) refreshLst(contcontdoc.getElementById("LstIex").contentWindow.document, srcdoc, 1, true, false, "FeedFLstIex",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstIexNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstIex"))]);
		};

		if ((ButIexViewAvail == !contcontdoc.getElementById("ButIexView")) || !contcontdoc.getElementById("ButIexNewcrd")) {
			if (LstIexAlt) mytd = contcontdoc.getElementById("dynIex");
			else mytd = contcontdoc.getElementById("rdynIex");
			clearElem(mytd);

			first = true;

			if (ButIexViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButIexView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButIexNewcrd", "icon/newcrd"));
		};

		if (ButIexViewAvail) refreshButicon(contcontdoc, "ButIexView", "icon/view", ButIexViewActive, false);
		refreshButicon(contcontdoc, "ButIexNewcrd", "icon/newcrd", ButIexNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Iex2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ime", LstImeAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ime2", LstImeAvail && !LstImeAlt, (LstImeAvail) ? 71 : 0);
	if (LstImeAvail) {
		if ( (LstImeAlt == !contcontdoc.getElementById("ButImeExpand")) || (!LstImeAlt == !contcontdoc.getElementById("ButImeCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynIme");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptIme", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptIme")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstImeAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButImeExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButImeCollapse", "icon/collapse"));
		};

		if (!LstImeAlt == !contcontdoc.getElementById("LstIme")) {
			mytd = contcontdoc.getElementById("rdynIme");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynIme");
			clearElem(mytd);

			if (LstImeAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstIme", "./PnlWznmNavDbstr_LstIme.xml", true));
			};

		} else {
			if (!LstImeAlt) refreshLst(contcontdoc.getElementById("LstIme").contentWindow.document, srcdoc, 1, true, false, "FeedFLstIme",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstImeNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstIme"))]);
		};

		if ((ButImeViewAvail == !contcontdoc.getElementById("ButImeView")) || !contcontdoc.getElementById("ButImeNewcrd")) {
			if (LstImeAlt) mytd = contcontdoc.getElementById("dynIme");
			else mytd = contcontdoc.getElementById("rdynIme");
			clearElem(mytd);

			first = true;

			if (ButImeViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButImeView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButImeNewcrd", "icon/newcrd"));
		};

		if (ButImeViewAvail) refreshButicon(contcontdoc, "ButImeView", "icon/view", ButImeViewActive, false);
		refreshButicon(contcontdoc, "ButImeNewcrd", "icon/newcrd", ButImeNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Ime2", false, 0);

	height -= setCtlAvail(contcontdoc, "Iel", LstIelAvail, 96);
	height -= setCtlAvail(contcontdoc, "Iel2", LstIelAvail && !LstIelAlt, (LstIelAvail) ? 71 : 0);
	if (LstIelAvail) {
		if ( (LstIelAlt == !contcontdoc.getElementById("ButIelExpand")) || (!LstIelAlt == !contcontdoc.getElementById("ButIelCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynIel");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptIel", retrieveTi(srcdoc, "TagWznmNavDbstr", "CptIel")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstIelAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButIelExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButIelCollapse", "icon/collapse"));
		};

		if (!LstIelAlt == !contcontdoc.getElementById("LstIel")) {
			mytd = contcontdoc.getElementById("rdynIel");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynIel");
			clearElem(mytd);

			if (LstIelAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstIel", "./PnlWznmNavDbstr_LstIel.xml", true));
			};

		} else {
			if (!LstIelAlt) refreshLst(contcontdoc.getElementById("LstIel").contentWindow.document, srcdoc, 1, true, false, "FeedFLstIel",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", "LstIelNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numFLstIel"))]);
		};

		if ((ButIelViewAvail == !contcontdoc.getElementById("ButIelView"))) {
			if (LstIelAlt) mytd = contcontdoc.getElementById("dynIel");
			else mytd = contcontdoc.getElementById("rdynIel");
			clearElem(mytd);

			first = true;

			if (ButIelViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButIelView", "icon/view"));
			};
		};

		if (ButIelViewAvail) refreshButicon(contcontdoc, "ButIelView", "icon/view", ButIelViewActive, false);

	} else setCtlAvail(contcontdoc, "Iel2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Dbstr", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Dbstr_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Dbstr_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Dbstr_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavDbstr", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Dbstr_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavDbstr", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavDbstr", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavDbstrDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavDbstrDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavDbstr", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavDbstr", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavDbstrData", scrJref, "ContIacWznmNavDbstr");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavDbstr", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavDbstr", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavDbstr", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "ContIacWznmNavDbstr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstChk", srcdoc)) mask.push("feedFLstChk");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstIel", srcdoc)) mask.push("feedFLstIel");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstIex", srcdoc)) mask.push("feedFLstIex");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstIme", srcdoc)) mask.push("feedFLstIme");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstRel", srcdoc)) mask.push("feedFLstRel");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstSbs", srcdoc)) mask.push("feedFLstSbs");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstStb", srcdoc)) mask.push("feedFLstStb");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstTbl", srcdoc)) mask.push("feedFLstTbl");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstTco", srcdoc)) mask.push("feedFLstTco");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstVec", srcdoc)) mask.push("feedFLstVec");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "FeedFLstVit", srcdoc)) mask.push("feedFLstVit");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "StatAppWznmNavDbstr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "StatShrWznmNavDbstr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavDbstrData", "TagWznmNavDbstr", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavDbstrData") {
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
			if (blk.nodeName == "DpchEngWznmNavDbstrData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Dbstr");
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

			} else if (blk.nodeName == "DpchEngWznmNavDbstrData") {
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

