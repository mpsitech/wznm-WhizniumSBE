/**
  * \file PnlWznmNavGlobal.js
  * web client functionality for panel PnlWznmNavGlobal
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Global", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Global_side").setAttribute("height", "30");
	doc.getElementById("Global_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Global_side").src = "./PnlWznmNavGlobal_aside.html";
	doc.getElementById("Global_cont").src = "./PnlWznmNavGlobal_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Global_side").src = "./PnlWznmNavGlobal_bside.html";
	doc.getElementById("Global_cont").src = "./PnlWznmNavGlobal_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavGlobal", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Global_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Global_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavGlobal", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate");

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

	var height = 586; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstLocAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstLocAlt") == "true");
	var LstLocAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstLocAvail") == "true");
	var ButLocViewAvail = !LstLocAlt;
	var ButLocViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButLocViewActive") == "true");

	var LstTagAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstTagAlt") == "true");
	var LstTagAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstTagAvail") == "true");
	var ButTagViewAvail = !LstTagAlt;
	var ButTagViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButTagViewActive") == "true");

	var LstCtpAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstCtpAlt") == "true");
	var LstCtpAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstCtpAvail") == "true");
	var ButCtpViewAvail = !LstCtpAlt;
	var ButCtpViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButCtpViewActive") == "true");

	var LstMtyAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstMtyAlt") == "true");
	var LstMtyAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstMtyAvail") == "true");
	var ButMtyViewAvail = !LstMtyAlt;
	var ButMtyViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButMtyViewActive") == "true");

	var LstMchAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstMchAlt") == "true");
	var LstMchAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstMchAvail") == "true");
	var ButMchViewAvail = !LstMchAlt;
	var ButMchViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButMchViewActive") == "true");

	var LstLibAlt = (retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstLibAlt") == "true");
	var LstLibAvail = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "LstLibAvail") == "true");
	var ButLibViewAvail = !LstLibAlt;
	var ButLibViewActive = (retrieveSi(srcdoc, "StatShrWznmNavGlobal", "ButLibViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Loc", LstLocAvail, 96);
	height -= setCtlAvail(contcontdoc, "Loc2", LstLocAvail && !LstLocAlt, (LstLocAvail) ? 71 : 0);
	if (LstLocAvail) {
		if ( (LstLocAlt == !contcontdoc.getElementById("ButLocExpand")) || (!LstLocAlt == !contcontdoc.getElementById("ButLocCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLoc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLoc", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptLoc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLocAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLocExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLocCollapse", "icon/collapse"));
		};

		if (!LstLocAlt == !contcontdoc.getElementById("LstLoc")) {
			mytd = contcontdoc.getElementById("rdynLoc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLoc");
			clearElem(mytd);

			if (LstLocAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLoc", "./PnlWznmNavGlobal_LstLoc.xml", true));
			};

		} else {
			if (!LstLocAlt) refreshLst(contcontdoc.getElementById("LstLoc").contentWindow.document, srcdoc, 1, true, false, "FeedFLstLoc",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstLocNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstLoc"))]);
		};

		if ((ButLocViewAvail == !contcontdoc.getElementById("ButLocView")) || !contcontdoc.getElementById("ButLocNewcrd")) {
			if (LstLocAlt) mytd = contcontdoc.getElementById("dynLoc");
			else mytd = contcontdoc.getElementById("rdynLoc");
			clearElem(mytd);

			first = true;

			if (ButLocViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLocView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLocNewcrd", "icon/newcrd"));
		};

		if (ButLocViewAvail) refreshButicon(contcontdoc, "ButLocView", "icon/view", ButLocViewActive, false);

	} else setCtlAvail(contcontdoc, "Loc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Tag", LstTagAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tag2", LstTagAvail && !LstTagAlt, (LstTagAvail) ? 71 : 0);
	if (LstTagAvail) {
		if ( (LstTagAlt == !contcontdoc.getElementById("ButTagExpand")) || (!LstTagAlt == !contcontdoc.getElementById("ButTagCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTag");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTag", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptTag")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTagAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTagExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTagCollapse", "icon/collapse"));
		};

		if (!LstTagAlt == !contcontdoc.getElementById("LstTag")) {
			mytd = contcontdoc.getElementById("rdynTag");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTag");
			clearElem(mytd);

			if (LstTagAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTag", "./PnlWznmNavGlobal_LstTag.xml", true));
			};

		} else {
			if (!LstTagAlt) refreshLst(contcontdoc.getElementById("LstTag").contentWindow.document, srcdoc, 1, true, false, "FeedFLstTag",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstTagNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstTag"))]);
		};

		if ((ButTagViewAvail == !contcontdoc.getElementById("ButTagView")) || !contcontdoc.getElementById("ButTagNewcrd")) {
			if (LstTagAlt) mytd = contcontdoc.getElementById("dynTag");
			else mytd = contcontdoc.getElementById("rdynTag");
			clearElem(mytd);

			first = true;

			if (ButTagViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTagView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTagNewcrd", "icon/newcrd"));
		};

		if (ButTagViewAvail) refreshButicon(contcontdoc, "ButTagView", "icon/view", ButTagViewActive, false);

	} else setCtlAvail(contcontdoc, "Tag2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ctp", LstCtpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ctp2", LstCtpAvail && !LstCtpAlt, (LstCtpAvail) ? 71 : 0);
	if (LstCtpAvail) {
		if ( (LstCtpAlt == !contcontdoc.getElementById("ButCtpExpand")) || (!LstCtpAlt == !contcontdoc.getElementById("ButCtpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCtp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCtp", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptCtp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCtpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCtpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCtpCollapse", "icon/collapse"));
		};

		if (!LstCtpAlt == !contcontdoc.getElementById("LstCtp")) {
			mytd = contcontdoc.getElementById("rdynCtp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCtp");
			clearElem(mytd);

			if (LstCtpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCtp", "./PnlWznmNavGlobal_LstCtp.xml", true));
			};

		} else {
			if (!LstCtpAlt) refreshLst(contcontdoc.getElementById("LstCtp").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCtp",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstCtpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstCtp"))]);
		};

		if ((ButCtpViewAvail == !contcontdoc.getElementById("ButCtpView")) || !contcontdoc.getElementById("ButCtpNewcrd")) {
			if (LstCtpAlt) mytd = contcontdoc.getElementById("dynCtp");
			else mytd = contcontdoc.getElementById("rdynCtp");
			clearElem(mytd);

			first = true;

			if (ButCtpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCtpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCtpNewcrd", "icon/newcrd"));
		};

		if (ButCtpViewAvail) refreshButicon(contcontdoc, "ButCtpView", "icon/view", ButCtpViewActive, false);

	} else setCtlAvail(contcontdoc, "Ctp2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mty", LstMtyAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mty2", LstMtyAvail && !LstMtyAlt, (LstMtyAvail) ? 71 : 0);
	if (LstMtyAvail) {
		if ( (LstMtyAlt == !contcontdoc.getElementById("ButMtyExpand")) || (!LstMtyAlt == !contcontdoc.getElementById("ButMtyCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMty");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMty", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptMty")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMtyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMtyExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMtyCollapse", "icon/collapse"));
		};

		if (!LstMtyAlt == !contcontdoc.getElementById("LstMty")) {
			mytd = contcontdoc.getElementById("rdynMty");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMty");
			clearElem(mytd);

			if (LstMtyAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMty", "./PnlWznmNavGlobal_LstMty.xml", true));
			};

		} else {
			if (!LstMtyAlt) refreshLst(contcontdoc.getElementById("LstMty").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMty",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstMtyNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstMty"))]);
		};

		if ((ButMtyViewAvail == !contcontdoc.getElementById("ButMtyView")) || !contcontdoc.getElementById("ButMtyNewcrd")) {
			if (LstMtyAlt) mytd = contcontdoc.getElementById("dynMty");
			else mytd = contcontdoc.getElementById("rdynMty");
			clearElem(mytd);

			first = true;

			if (ButMtyViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMtyView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMtyNewcrd", "icon/newcrd"));
		};

		if (ButMtyViewAvail) refreshButicon(contcontdoc, "ButMtyView", "icon/view", ButMtyViewActive, false);

	} else setCtlAvail(contcontdoc, "Mty2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mch", LstMchAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mch2", LstMchAvail && !LstMchAlt, (LstMchAvail) ? 71 : 0);
	if (LstMchAvail) {
		if ( (LstMchAlt == !contcontdoc.getElementById("ButMchExpand")) || (!LstMchAlt == !contcontdoc.getElementById("ButMchCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMch");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMch", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptMch")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMchAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMchExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMchCollapse", "icon/collapse"));
		};

		if (!LstMchAlt == !contcontdoc.getElementById("LstMch")) {
			mytd = contcontdoc.getElementById("rdynMch");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMch");
			clearElem(mytd);

			if (LstMchAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMch", "./PnlWznmNavGlobal_LstMch.xml", true));
			};

		} else {
			if (!LstMchAlt) refreshLst(contcontdoc.getElementById("LstMch").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMch",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstMchNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstMch"))]);
		};

		if ((ButMchViewAvail == !contcontdoc.getElementById("ButMchView")) || !contcontdoc.getElementById("ButMchNewcrd")) {
			if (LstMchAlt) mytd = contcontdoc.getElementById("dynMch");
			else mytd = contcontdoc.getElementById("rdynMch");
			clearElem(mytd);

			first = true;

			if (ButMchViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMchView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMchNewcrd", "icon/newcrd"));
		};

		if (ButMchViewAvail) refreshButicon(contcontdoc, "ButMchView", "icon/view", ButMchViewActive, false);

	} else setCtlAvail(contcontdoc, "Mch2", false, 0);

	height -= setCtlAvail(contcontdoc, "Lib", LstLibAvail, 96);
	height -= setCtlAvail(contcontdoc, "Lib2", LstLibAvail && !LstLibAlt, (LstLibAvail) ? 71 : 0);
	if (LstLibAvail) {
		if ( (LstLibAlt == !contcontdoc.getElementById("ButLibExpand")) || (!LstLibAlt == !contcontdoc.getElementById("ButLibCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLib");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLib", retrieveTi(srcdoc, "TagWznmNavGlobal", "CptLib")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLibAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLibExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLibCollapse", "icon/collapse"));
		};

		if (!LstLibAlt == !contcontdoc.getElementById("LstLib")) {
			mytd = contcontdoc.getElementById("rdynLib");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLib");
			clearElem(mytd);

			if (LstLibAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLib", "./PnlWznmNavGlobal_LstLib.xml", true));
			};

		} else {
			if (!LstLibAlt) refreshLst(contcontdoc.getElementById("LstLib").contentWindow.document, srcdoc, 1, true, false, "FeedFLstLib",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", "LstLibNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numFLstLib"))]);
		};

		if ((ButLibViewAvail == !contcontdoc.getElementById("ButLibView")) || !contcontdoc.getElementById("ButLibNewcrd")) {
			if (LstLibAlt) mytd = contcontdoc.getElementById("dynLib");
			else mytd = contcontdoc.getElementById("rdynLib");
			clearElem(mytd);

			first = true;

			if (ButLibViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLibView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLibNewcrd", "icon/newcrd"));
		};

		if (ButLibViewAvail) refreshButicon(contcontdoc, "ButLibView", "icon/view", ButLibViewActive, false);

	} else setCtlAvail(contcontdoc, "Lib2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Global", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Global_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavGlobal", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Global_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavGlobal", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavGlobal", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavGlobal", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavGlobal", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavGlobalData", scrJref, "ContIacWznmNavGlobal");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavGlobal", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavGlobal", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavGlobal", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "ContIacWznmNavGlobal", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstCtp", srcdoc)) mask.push("feedFLstCtp");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstLib", srcdoc)) mask.push("feedFLstLib");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstLoc", srcdoc)) mask.push("feedFLstLoc");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstMch", srcdoc)) mask.push("feedFLstMch");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstMty", srcdoc)) mask.push("feedFLstMty");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "FeedFLstTag", srcdoc)) mask.push("feedFLstTag");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "StatAppWznmNavGlobal", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "StatShrWznmNavGlobal", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavGlobalData", "TagWznmNavGlobal", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavGlobalData") {
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
			if (blk.nodeName == "DpchEngWznmNavGlobalData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Global");
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

			} else if (blk.nodeName == "DpchEngWznmNavGlobalData") {
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

