/**
  * \file PnlWznmNavJob.js
  * web client functionality for panel PnlWznmNavJob
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Job", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Job_side").setAttribute("height", "30");
	doc.getElementById("Job_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Job_side").src = "./PnlWznmNavJob_aside.html";
	doc.getElementById("Job_cont").src = "./PnlWznmNavJob_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Job_side").src = "./PnlWznmNavJob_bside.html";
	doc.getElementById("Job_cont").src = "./PnlWznmNavJob_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Job_side").contentDocument;
	contdoc = doc.getElementById("Job_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavJob", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Job_side").contentDocument;
	contdoc = doc.getElementById("Job_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Job_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Job_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWznmNavJob", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate");

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

	var height = 490; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstJobAlt = (retrieveSi(srcdoc, "StatAppWznmNavJob", "LstJobAlt") == "true");
	var LstJobAvail = (retrieveSi(srcdoc, "StatShrWznmNavJob", "LstJobAvail") == "true");
	var ButJobViewAvail = !LstJobAlt;
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButJobViewActive") == "true");
	var ButJobNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButJobNewcrdActive") == "true");

	var LstSgeAlt = (retrieveSi(srcdoc, "StatAppWznmNavJob", "LstSgeAlt") == "true");
	var LstSgeAvail = (retrieveSi(srcdoc, "StatShrWznmNavJob", "LstSgeAvail") == "true");
	var ButSgeViewAvail = !LstSgeAlt;
	var ButSgeViewActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButSgeViewActive") == "true");
	var ButSgeNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButSgeNewcrdActive") == "true");

	var LstMtdAlt = (retrieveSi(srcdoc, "StatAppWznmNavJob", "LstMtdAlt") == "true");
	var LstMtdAvail = (retrieveSi(srcdoc, "StatShrWznmNavJob", "LstMtdAvail") == "true");
	var ButMtdViewAvail = !LstMtdAlt;
	var ButMtdViewActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButMtdViewActive") == "true");
	var ButMtdNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButMtdNewcrdActive") == "true");

	var LstBlkAlt = (retrieveSi(srcdoc, "StatAppWznmNavJob", "LstBlkAlt") == "true");
	var LstBlkAvail = (retrieveSi(srcdoc, "StatShrWznmNavJob", "LstBlkAvail") == "true");
	var ButBlkViewAvail = !LstBlkAlt;
	var ButBlkViewActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButBlkViewActive") == "true");
	var ButBlkNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButBlkNewcrdActive") == "true");

	var LstCalAlt = (retrieveSi(srcdoc, "StatAppWznmNavJob", "LstCalAlt") == "true");
	var LstCalAvail = (retrieveSi(srcdoc, "StatShrWznmNavJob", "LstCalAvail") == "true");
	var ButCalViewAvail = !LstCalAlt;
	var ButCalViewActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButCalViewActive") == "true");
	var ButCalNewcrdActive = (retrieveSi(srcdoc, "StatShrWznmNavJob", "ButCalNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Job", LstJobAvail, 96);
	height -= setCtlAvail(contcontdoc, "Job2", LstJobAvail && !LstJobAlt, (LstJobAvail) ? 71 : 0);
	if (LstJobAvail) {
		if ( (LstJobAlt == !contcontdoc.getElementById("ButJobExpand")) || (!LstJobAlt == !contcontdoc.getElementById("ButJobCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynJob");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWznmNavJob", "CptJob")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstJobAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButJobExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButJobCollapse", "icon/collapse"));
		};

		if (!LstJobAlt == !contcontdoc.getElementById("LstJob")) {
			mytd = contcontdoc.getElementById("rdynJob");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynJob");
			clearElem(mytd);

			if (LstJobAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstJob", "./PnlWznmNavJob_LstJob.xml", true));
			};

		} else {
			if (!LstJobAlt) refreshLst(contcontdoc.getElementById("LstJob").contentWindow.document, srcdoc, 1, true, false, "FeedFLstJob",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", "LstJobNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numFLstJob"))]);
		};

		if ((ButJobViewAvail == !contcontdoc.getElementById("ButJobView")) || !contcontdoc.getElementById("ButJobNewcrd")) {
			if (LstJobAlt) mytd = contcontdoc.getElementById("dynJob");
			else mytd = contcontdoc.getElementById("rdynJob");
			clearElem(mytd);

			first = true;

			if (ButJobViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButJobView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJobNewcrd", "icon/newcrd"));
		};

		if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);
		refreshButicon(contcontdoc, "ButJobNewcrd", "icon/newcrd", ButJobNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Job2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sge", LstSgeAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sge2", LstSgeAvail && !LstSgeAlt, (LstSgeAvail) ? 71 : 0);
	if (LstSgeAvail) {
		if ( (LstSgeAlt == !contcontdoc.getElementById("ButSgeExpand")) || (!LstSgeAlt == !contcontdoc.getElementById("ButSgeCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSge");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSge", retrieveTi(srcdoc, "TagWznmNavJob", "CptSge")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSgeAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSgeExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSgeCollapse", "icon/collapse"));
		};

		if (!LstSgeAlt == !contcontdoc.getElementById("LstSge")) {
			mytd = contcontdoc.getElementById("rdynSge");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSge");
			clearElem(mytd);

			if (LstSgeAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSge", "./PnlWznmNavJob_LstSge.xml", true));
			};

		} else {
			if (!LstSgeAlt) refreshLst(contcontdoc.getElementById("LstSge").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSge",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", "LstSgeNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numFLstSge"))]);
		};

		if ((ButSgeViewAvail == !contcontdoc.getElementById("ButSgeView")) || !contcontdoc.getElementById("ButSgeNewcrd")) {
			if (LstSgeAlt) mytd = contcontdoc.getElementById("dynSge");
			else mytd = contcontdoc.getElementById("rdynSge");
			clearElem(mytd);

			first = true;

			if (ButSgeViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSgeView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSgeNewcrd", "icon/newcrd"));
		};

		if (ButSgeViewAvail) refreshButicon(contcontdoc, "ButSgeView", "icon/view", ButSgeViewActive, false);
		refreshButicon(contcontdoc, "ButSgeNewcrd", "icon/newcrd", ButSgeNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sge2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mtd", LstMtdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mtd2", LstMtdAvail && !LstMtdAlt, (LstMtdAvail) ? 71 : 0);
	if (LstMtdAvail) {
		if ( (LstMtdAlt == !contcontdoc.getElementById("ButMtdExpand")) || (!LstMtdAlt == !contcontdoc.getElementById("ButMtdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMtd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMtd", retrieveTi(srcdoc, "TagWznmNavJob", "CptMtd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMtdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMtdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMtdCollapse", "icon/collapse"));
		};

		if (!LstMtdAlt == !contcontdoc.getElementById("LstMtd")) {
			mytd = contcontdoc.getElementById("rdynMtd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMtd");
			clearElem(mytd);

			if (LstMtdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMtd", "./PnlWznmNavJob_LstMtd.xml", true));
			};

		} else {
			if (!LstMtdAlt) refreshLst(contcontdoc.getElementById("LstMtd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMtd",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", "LstMtdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numFLstMtd"))]);
		};

		if ((ButMtdViewAvail == !contcontdoc.getElementById("ButMtdView")) || !contcontdoc.getElementById("ButMtdNewcrd")) {
			if (LstMtdAlt) mytd = contcontdoc.getElementById("dynMtd");
			else mytd = contcontdoc.getElementById("rdynMtd");
			clearElem(mytd);

			first = true;

			if (ButMtdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMtdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMtdNewcrd", "icon/newcrd"));
		};

		if (ButMtdViewAvail) refreshButicon(contcontdoc, "ButMtdView", "icon/view", ButMtdViewActive, false);
		refreshButicon(contcontdoc, "ButMtdNewcrd", "icon/newcrd", ButMtdNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Mtd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Blk", LstBlkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Blk2", LstBlkAvail && !LstBlkAlt, (LstBlkAvail) ? 71 : 0);
	if (LstBlkAvail) {
		if ( (LstBlkAlt == !contcontdoc.getElementById("ButBlkExpand")) || (!LstBlkAlt == !contcontdoc.getElementById("ButBlkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynBlk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptBlk", retrieveTi(srcdoc, "TagWznmNavJob", "CptBlk")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstBlkAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButBlkExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButBlkCollapse", "icon/collapse"));
		};

		if (!LstBlkAlt == !contcontdoc.getElementById("LstBlk")) {
			mytd = contcontdoc.getElementById("rdynBlk");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynBlk");
			clearElem(mytd);

			if (LstBlkAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstBlk", "./PnlWznmNavJob_LstBlk.xml", true));
			};

		} else {
			if (!LstBlkAlt) refreshLst(contcontdoc.getElementById("LstBlk").contentWindow.document, srcdoc, 1, true, false, "FeedFLstBlk",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", "LstBlkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numFLstBlk"))]);
		};

		if ((ButBlkViewAvail == !contcontdoc.getElementById("ButBlkView")) || !contcontdoc.getElementById("ButBlkNewcrd")) {
			if (LstBlkAlt) mytd = contcontdoc.getElementById("dynBlk");
			else mytd = contcontdoc.getElementById("rdynBlk");
			clearElem(mytd);

			first = true;

			if (ButBlkViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButBlkView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBlkNewcrd", "icon/newcrd"));
		};

		if (ButBlkViewAvail) refreshButicon(contcontdoc, "ButBlkView", "icon/view", ButBlkViewActive, false);
		refreshButicon(contcontdoc, "ButBlkNewcrd", "icon/newcrd", ButBlkNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Blk2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cal", LstCalAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cal2", LstCalAvail && !LstCalAlt, (LstCalAvail) ? 71 : 0);
	if (LstCalAvail) {
		if ( (LstCalAlt == !contcontdoc.getElementById("ButCalExpand")) || (!LstCalAlt == !contcontdoc.getElementById("ButCalCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCal");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagWznmNavJob", "CptCal")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCalAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCalExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCalCollapse", "icon/collapse"));
		};

		if (!LstCalAlt == !contcontdoc.getElementById("LstCal")) {
			mytd = contcontdoc.getElementById("rdynCal");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCal");
			clearElem(mytd);

			if (LstCalAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCal", "./PnlWznmNavJob_LstCal.xml", true));
			};

		} else {
			if (!LstCalAlt) refreshLst(contcontdoc.getElementById("LstCal").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCal",
						parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", "LstCalNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numFLstCal"))]);
		};

		if ((ButCalViewAvail == !contcontdoc.getElementById("ButCalView")) || !contcontdoc.getElementById("ButCalNewcrd")) {
			if (LstCalAlt) mytd = contcontdoc.getElementById("dynCal");
			else mytd = contcontdoc.getElementById("rdynCal");
			clearElem(mytd);

			first = true;

			if (ButCalViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCalView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCalNewcrd", "icon/newcrd"));
		};

		if (ButCalViewAvail) refreshButicon(contcontdoc, "ButCalView", "icon/view", ButCalViewActive, false);
		refreshButicon(contcontdoc, "ButCalNewcrd", "icon/newcrd", ButCalNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cal2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Job", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Job_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Job_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Job_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatAppWznmNavJob", "srefIxWznmVExpstate");

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
	srcdoc = doc.getElementById("Job_src").contentDocument;

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
	setSi(srcdoc, "StatAppWznmNavJob", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWznmNavJob", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavJobDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavJobDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavJob", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavJob", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWznmNavJob", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWznmNavJob", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWznmNavJobData", scrJref, "ContIacWznmNavJob");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWznmNavJob", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWznmNavJob", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWznmNavJob", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWznmNavJob", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "ContIacWznmNavJob", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "FeedFLstBlk", srcdoc)) mask.push("feedFLstBlk");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "FeedFLstCal", srcdoc)) mask.push("feedFLstCal");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "FeedFLstJob", srcdoc)) mask.push("feedFLstJob");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "FeedFLstMtd", srcdoc)) mask.push("feedFLstMtd");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "FeedFLstSge", srcdoc)) mask.push("feedFLstSge");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "StatAppWznmNavJob", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "StatShrWznmNavJob", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavJobData", "TagWznmNavJob", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWznmNavJobData") {
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
			if (blk.nodeName == "DpchEngWznmNavJobData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Job");
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

			} else if (blk.nodeName == "DpchEngWznmNavJobData") {
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

