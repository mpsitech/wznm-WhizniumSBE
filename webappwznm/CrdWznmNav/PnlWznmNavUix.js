/**
  * \file PnlWznmNavUix.js
  * web client functionality for panel PnlWznmNavUix
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Uix", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Uix_side").setAttribute("height", "30");
	doc.getElementById("Uix_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Uix_side").src = "./PnlWznmNavUix_aside.html";
	doc.getElementById("Uix_cont").src = "./PnlWznmNavUix_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Uix_side").src = "./PnlWznmNavUix_bside.html";
	doc.getElementById("Uix_cont").src = "./PnlWznmNavUix_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Uix_side").contentDocument;
	contdoc = doc.getElementById("Uix_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavUix", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Uix_side").contentDocument;
	contdoc = doc.getElementById("Uix_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Uix_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Uix_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavUix", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate");

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

	var height = 874; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstPstAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstPstAlt") == "true");
	var LstPstAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstPstAvail") == "true");
	var ButPstViewAvail = !LstPstAlt;
	var ButPstViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButPstViewActive") == "true");
	var ButPstNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButPstNewcrdActive") == "true");

	var LstMdlAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstMdlAlt") == "true");
	var LstMdlAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstMdlAvail") == "true");
	var ButMdlViewAvail = !LstMdlAlt;
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButMdlViewActive") == "true");
	var ButMdlNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButMdlNewcrdActive") == "true");

	var LstCarAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstCarAlt") == "true");
	var LstCarAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstCarAvail") == "true");
	var ButCarViewAvail = !LstCarAlt;
	var ButCarViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButCarViewActive") == "true");
	var ButCarNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButCarNewcrdActive") == "true");

	var LstDlgAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstDlgAlt") == "true");
	var LstDlgAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstDlgAvail") == "true");
	var ButDlgViewAvail = !LstDlgAlt;
	var ButDlgViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButDlgViewActive") == "true");
	var ButDlgNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButDlgNewcrdActive") == "true");

	var LstPnlAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstPnlAlt") == "true");
	var LstPnlAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstPnlAvail") == "true");
	var ButPnlViewAvail = !LstPnlAlt;
	var ButPnlViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButPnlViewActive") == "true");
	var ButPnlNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButPnlNewcrdActive") == "true");

	var LstQryAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQryAlt") == "true");
	var LstQryAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstQryAvail") == "true");
	var ButQryViewAvail = !LstQryAlt;
	var ButQryViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQryViewActive") == "true");
	var ButQryNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQryNewcrdActive") == "true");

	var LstQcoAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQcoAlt") == "true");
	var LstQcoAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstQcoAvail") == "true");
	var ButQcoViewAvail = !LstQcoAlt;
	var ButQcoViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQcoViewActive") == "true");
	var ButQcoNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQcoNewcrdActive") == "true");

	var LstQmdAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQmdAlt") == "true");
	var LstQmdAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstQmdAvail") == "true");
	var ButQmdViewAvail = !LstQmdAlt;
	var ButQmdViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQmdViewActive") == "true");
	var ButQmdNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButQmdNewcrdActive") == "true");

	var LstConAlt = (retrieveSi(srcdoc, "StatAppWznmNavUix", "LstConAlt") == "true");
	var LstConAvail = (retrieveSi(srcdoc, "StatShrWznmNavUix", "LstConAvail") == "true");
	var ButConViewAvail = !LstConAlt;
	var ButConViewActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButConViewActive") == "true");
	var ButConNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavUix", "ButConNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Pst", LstPstAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pst2", LstPstAvail && !LstPstAlt, (LstPstAvail) ? 71 : 0);
	if (LstPstAvail) {
		if ( (LstPstAlt == !contcontdoc.getElementById("ButPstExpand")) || (!LstPstAlt == !contcontdoc.getElementById("ButPstCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPst");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPst", retrieveTi(srcdoc, "TagWznmNavUix", "CptPst")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPstAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPstExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPstCollapse", "icon/collapse"));
		};

		if (!LstPstAlt == !contcontdoc.getElementById("LstPst")) {
			mytd = contcontdoc.getElementById("rdynPst");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPst");
			clearElem(mytd);

			if (LstPstAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPst", "./PnlWznmNavUix_LstPst.xml", true));
			};

		} else {
			if (!LstPstAlt) refreshLst(contcontdoc.getElementById("LstPst").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPst",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstPstNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstPst"))]);
		};

		if ((ButPstViewAvail == !contcontdoc.getElementById("ButPstView")) || !contcontdoc.getElementById("ButPstNewcrd")) {
			if (LstPstAlt) mytd = contcontdoc.getElementById("dynPst");
			else mytd = contcontdoc.getElementById("rdynPst");
			clearElem(mytd);

			first = true;

			if (ButPstViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstNewcrd", "icon/newcrd"));
		};

		if (ButPstViewAvail) refreshButicon(contcontdoc, "ButPstView", "icon/view", ButPstViewActive, false);
		refreshButicon(contcontdoc, "ButPstNewcrd", "icon/newcrd", ButPstNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Pst2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mdl", LstMdlAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mdl2", LstMdlAvail && !LstMdlAlt, (LstMdlAvail) ? 71 : 0);
	if (LstMdlAvail) {
		if ( (LstMdlAlt == !contcontdoc.getElementById("ButMdlExpand")) || (!LstMdlAlt == !contcontdoc.getElementById("ButMdlCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMdl");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWznmNavUix", "CptMdl")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMdlAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMdlExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMdlCollapse", "icon/collapse"));
		};

		if (!LstMdlAlt == !contcontdoc.getElementById("LstMdl")) {
			mytd = contcontdoc.getElementById("rdynMdl");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMdl");
			clearElem(mytd);

			if (LstMdlAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMdl", "./PnlWznmNavUix_LstMdl.xml", true));
			};

		} else {
			if (!LstMdlAlt) refreshLst(contcontdoc.getElementById("LstMdl").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMdl",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstMdlNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstMdl"))]);
		};

		if ((ButMdlViewAvail == !contcontdoc.getElementById("ButMdlView")) || !contcontdoc.getElementById("ButMdlNewcrd")) {
			if (LstMdlAlt) mytd = contcontdoc.getElementById("dynMdl");
			else mytd = contcontdoc.getElementById("rdynMdl");
			clearElem(mytd);

			first = true;

			if (ButMdlViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMdlView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMdlNewcrd", "icon/newcrd"));
		};

		if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);
		refreshButicon(contcontdoc, "ButMdlNewcrd", "icon/newcrd", ButMdlNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Mdl2", false, 0);

	height -= setCtlAvail(contcontdoc, "Car", LstCarAvail, 96);
	height -= setCtlAvail(contcontdoc, "Car2", LstCarAvail && !LstCarAlt, (LstCarAvail) ? 71 : 0);
	if (LstCarAvail) {
		if ( (LstCarAlt == !contcontdoc.getElementById("ButCarExpand")) || (!LstCarAlt == !contcontdoc.getElementById("ButCarCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCar");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCar", retrieveTi(srcdoc, "TagWznmNavUix", "CptCar")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCarAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCarExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCarCollapse", "icon/collapse"));
		};

		if (!LstCarAlt == !contcontdoc.getElementById("LstCar")) {
			mytd = contcontdoc.getElementById("rdynCar");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCar");
			clearElem(mytd);

			if (LstCarAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCar", "./PnlWznmNavUix_LstCar.xml", true));
			};

		} else {
			if (!LstCarAlt) refreshLst(contcontdoc.getElementById("LstCar").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCar",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstCarNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstCar"))]);
		};

		if ((ButCarViewAvail == !contcontdoc.getElementById("ButCarView")) || !contcontdoc.getElementById("ButCarNewcrd")) {
			if (LstCarAlt) mytd = contcontdoc.getElementById("dynCar");
			else mytd = contcontdoc.getElementById("rdynCar");
			clearElem(mytd);

			first = true;

			if (ButCarViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCarView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCarNewcrd", "icon/newcrd"));
		};

		if (ButCarViewAvail) refreshButicon(contcontdoc, "ButCarView", "icon/view", ButCarViewActive, false);
		refreshButicon(contcontdoc, "ButCarNewcrd", "icon/newcrd", ButCarNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Car2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dlg", LstDlgAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dlg2", LstDlgAvail && !LstDlgAlt, (LstDlgAvail) ? 71 : 0);
	if (LstDlgAvail) {
		if ( (LstDlgAlt == !contcontdoc.getElementById("ButDlgExpand")) || (!LstDlgAlt == !contcontdoc.getElementById("ButDlgCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDlg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDlg", retrieveTi(srcdoc, "TagWznmNavUix", "CptDlg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDlgAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDlgExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDlgCollapse", "icon/collapse"));
		};

		if (!LstDlgAlt == !contcontdoc.getElementById("LstDlg")) {
			mytd = contcontdoc.getElementById("rdynDlg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDlg");
			clearElem(mytd);

			if (LstDlgAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDlg", "./PnlWznmNavUix_LstDlg.xml", true));
			};

		} else {
			if (!LstDlgAlt) refreshLst(contcontdoc.getElementById("LstDlg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstDlg",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstDlgNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstDlg"))]);
		};

		if ((ButDlgViewAvail == !contcontdoc.getElementById("ButDlgView")) || !contcontdoc.getElementById("ButDlgNewcrd")) {
			if (LstDlgAlt) mytd = contcontdoc.getElementById("dynDlg");
			else mytd = contcontdoc.getElementById("rdynDlg");
			clearElem(mytd);

			first = true;

			if (ButDlgViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDlgView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDlgNewcrd", "icon/newcrd"));
		};

		if (ButDlgViewAvail) refreshButicon(contcontdoc, "ButDlgView", "icon/view", ButDlgViewActive, false);
		refreshButicon(contcontdoc, "ButDlgNewcrd", "icon/newcrd", ButDlgNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Dlg2", false, 0);

	height -= setCtlAvail(contcontdoc, "Pnl", LstPnlAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pnl2", LstPnlAvail && !LstPnlAlt, (LstPnlAvail) ? 71 : 0);
	if (LstPnlAvail) {
		if ( (LstPnlAlt == !contcontdoc.getElementById("ButPnlExpand")) || (!LstPnlAlt == !contcontdoc.getElementById("ButPnlCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPnl");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPnl", retrieveTi(srcdoc, "TagWznmNavUix", "CptPnl")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPnlAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPnlExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPnlCollapse", "icon/collapse"));
		};

		if (!LstPnlAlt == !contcontdoc.getElementById("LstPnl")) {
			mytd = contcontdoc.getElementById("rdynPnl");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPnl");
			clearElem(mytd);

			if (LstPnlAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPnl", "./PnlWznmNavUix_LstPnl.xml", true));
			};

		} else {
			if (!LstPnlAlt) refreshLst(contcontdoc.getElementById("LstPnl").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPnl",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstPnlNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstPnl"))]);
		};

		if ((ButPnlViewAvail == !contcontdoc.getElementById("ButPnlView")) || !contcontdoc.getElementById("ButPnlNewcrd")) {
			if (LstPnlAlt) mytd = contcontdoc.getElementById("dynPnl");
			else mytd = contcontdoc.getElementById("rdynPnl");
			clearElem(mytd);

			first = true;

			if (ButPnlViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPnlView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPnlNewcrd", "icon/newcrd"));
		};

		if (ButPnlViewAvail) refreshButicon(contcontdoc, "ButPnlView", "icon/view", ButPnlViewActive, false);
		refreshButicon(contcontdoc, "ButPnlNewcrd", "icon/newcrd", ButPnlNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Pnl2", false, 0);

	height -= setCtlAvail(contcontdoc, "Qry", LstQryAvail, 96);
	height -= setCtlAvail(contcontdoc, "Qry2", LstQryAvail && !LstQryAlt, (LstQryAvail) ? 71 : 0);
	if (LstQryAvail) {
		if ( (LstQryAlt == !contcontdoc.getElementById("ButQryExpand")) || (!LstQryAlt == !contcontdoc.getElementById("ButQryCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynQry");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptQry", retrieveTi(srcdoc, "TagWznmNavUix", "CptQry")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstQryAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButQryExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButQryCollapse", "icon/collapse"));
		};

		if (!LstQryAlt == !contcontdoc.getElementById("LstQry")) {
			mytd = contcontdoc.getElementById("rdynQry");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynQry");
			clearElem(mytd);

			if (LstQryAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstQry", "./PnlWznmNavUix_LstQry.xml", true));
			};

		} else {
			if (!LstQryAlt) refreshLst(contcontdoc.getElementById("LstQry").contentWindow.document, srcdoc, 1, true, false, "FeedFLstQry",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQryNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstQry"))]);
		};

		if ((ButQryViewAvail == !contcontdoc.getElementById("ButQryView")) || !contcontdoc.getElementById("ButQryNewcrd")) {
			if (LstQryAlt) mytd = contcontdoc.getElementById("dynQry");
			else mytd = contcontdoc.getElementById("rdynQry");
			clearElem(mytd);

			first = true;

			if (ButQryViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButQryView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButQryNewcrd", "icon/newcrd"));
		};

		if (ButQryViewAvail) refreshButicon(contcontdoc, "ButQryView", "icon/view", ButQryViewActive, false);
		refreshButicon(contcontdoc, "ButQryNewcrd", "icon/newcrd", ButQryNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Qry2", false, 0);

	height -= setCtlAvail(contcontdoc, "Qco", LstQcoAvail, 96);
	height -= setCtlAvail(contcontdoc, "Qco2", LstQcoAvail && !LstQcoAlt, (LstQcoAvail) ? 71 : 0);
	if (LstQcoAvail) {
		if ( (LstQcoAlt == !contcontdoc.getElementById("ButQcoExpand")) || (!LstQcoAlt == !contcontdoc.getElementById("ButQcoCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynQco");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptQco", retrieveTi(srcdoc, "TagWznmNavUix", "CptQco")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstQcoAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButQcoExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButQcoCollapse", "icon/collapse"));
		};

		if (!LstQcoAlt == !contcontdoc.getElementById("LstQco")) {
			mytd = contcontdoc.getElementById("rdynQco");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynQco");
			clearElem(mytd);

			if (LstQcoAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstQco", "./PnlWznmNavUix_LstQco.xml", true));
			};

		} else {
			if (!LstQcoAlt) refreshLst(contcontdoc.getElementById("LstQco").contentWindow.document, srcdoc, 1, true, false, "FeedFLstQco",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQcoNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstQco"))]);
		};

		if ((ButQcoViewAvail == !contcontdoc.getElementById("ButQcoView")) || !contcontdoc.getElementById("ButQcoNewcrd")) {
			if (LstQcoAlt) mytd = contcontdoc.getElementById("dynQco");
			else mytd = contcontdoc.getElementById("rdynQco");
			clearElem(mytd);

			first = true;

			if (ButQcoViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButQcoView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButQcoNewcrd", "icon/newcrd"));
		};

		if (ButQcoViewAvail) refreshButicon(contcontdoc, "ButQcoView", "icon/view", ButQcoViewActive, false);
		refreshButicon(contcontdoc, "ButQcoNewcrd", "icon/newcrd", ButQcoNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Qco2", false, 0);

	height -= setCtlAvail(contcontdoc, "Qmd", LstQmdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Qmd2", LstQmdAvail && !LstQmdAlt, (LstQmdAvail) ? 71 : 0);
	if (LstQmdAvail) {
		if ( (LstQmdAlt == !contcontdoc.getElementById("ButQmdExpand")) || (!LstQmdAlt == !contcontdoc.getElementById("ButQmdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynQmd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptQmd", retrieveTi(srcdoc, "TagWznmNavUix", "CptQmd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstQmdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButQmdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButQmdCollapse", "icon/collapse"));
		};

		if (!LstQmdAlt == !contcontdoc.getElementById("LstQmd")) {
			mytd = contcontdoc.getElementById("rdynQmd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynQmd");
			clearElem(mytd);

			if (LstQmdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstQmd", "./PnlWznmNavUix_LstQmd.xml", true));
			};

		} else {
			if (!LstQmdAlt) refreshLst(contcontdoc.getElementById("LstQmd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstQmd",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstQmdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstQmd"))]);
		};

		if ((ButQmdViewAvail == !contcontdoc.getElementById("ButQmdView")) || !contcontdoc.getElementById("ButQmdNewcrd")) {
			if (LstQmdAlt) mytd = contcontdoc.getElementById("dynQmd");
			else mytd = contcontdoc.getElementById("rdynQmd");
			clearElem(mytd);

			first = true;

			if (ButQmdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButQmdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButQmdNewcrd", "icon/newcrd"));
		};

		if (ButQmdViewAvail) refreshButicon(contcontdoc, "ButQmdView", "icon/view", ButQmdViewActive, false);
		refreshButicon(contcontdoc, "ButQmdNewcrd", "icon/newcrd", ButQmdNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Qmd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Con", LstConAvail, 96);
	height -= setCtlAvail(contcontdoc, "Con2", LstConAvail && !LstConAlt, (LstConAvail) ? 71 : 0);
	if (LstConAvail) {
		if ( (LstConAlt == !contcontdoc.getElementById("ButConExpand")) || (!LstConAlt == !contcontdoc.getElementById("ButConCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCon");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCon", retrieveTi(srcdoc, "TagWznmNavUix", "CptCon")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstConAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButConExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButConCollapse", "icon/collapse"));
		};

		if (!LstConAlt == !contcontdoc.getElementById("LstCon")) {
			mytd = contcontdoc.getElementById("rdynCon");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCon");
			clearElem(mytd);

			if (LstConAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCon", "./PnlWznmNavUix_LstCon.xml", true));
			};

		} else {
			if (!LstConAlt) refreshLst(contcontdoc.getElementById("LstCon").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCon",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", "LstConNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numFLstCon"))]);
		};

		if ((ButConViewAvail == !contcontdoc.getElementById("ButConView")) || !contcontdoc.getElementById("ButConNewcrd")) {
			if (LstConAlt) mytd = contcontdoc.getElementById("dynCon");
			else mytd = contcontdoc.getElementById("rdynCon");
			clearElem(mytd);

			first = true;

			if (ButConViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButConView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButConNewcrd", "icon/newcrd"));
		};

		if (ButConViewAvail) refreshButicon(contcontdoc, "ButConView", "icon/view", ButConViewActive, false);
		refreshButicon(contcontdoc, "ButConNewcrd", "icon/newcrd", ButConNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Con2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Uix", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Uix_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Uix_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Uix_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavUix", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Uix_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavUix", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavUix", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavUixDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavUixDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavUix", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavUix", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavUix", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavUix", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavUixData", scrJref, "ContIacWznmNavUix");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavUix", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavUix", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavUix", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavUix", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "ContIacWznmNavUix", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstCar", srcdoc)) mask.push("feedFLstCar");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstCon", srcdoc)) mask.push("feedFLstCon");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstDlg", srcdoc)) mask.push("feedFLstDlg");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstMdl", srcdoc)) mask.push("feedFLstMdl");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstPnl", srcdoc)) mask.push("feedFLstPnl");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstPst", srcdoc)) mask.push("feedFLstPst");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstQco", srcdoc)) mask.push("feedFLstQco");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstQmd", srcdoc)) mask.push("feedFLstQmd");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "FeedFLstQry", srcdoc)) mask.push("feedFLstQry");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "StatAppWznmNavUix", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "StatShrWznmNavUix", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavUixData", "TagWznmNavUix", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavUixData") {
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
			if (blk.nodeName == "DpchEngWznmNavUixData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Uix");
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

			} else if (blk.nodeName == "DpchEngWznmNavUixData") {
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

