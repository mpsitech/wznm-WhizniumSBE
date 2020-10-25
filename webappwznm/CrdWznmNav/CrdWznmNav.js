/**
  * \file CrdWznmNav.js
  * web client functionality for card CrdWznmNav
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneHeadbar") == "true");
	var initdonePre = (retrieveSi(srcdoc, "StatAppWznmNav", "initdonePre") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneAdmin") == "true");
	var initdoneGlobal = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneGlobal") == "true");
	var initdoneProject = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneProject") == "true");
	var initdoneDbstr = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneDbstr") == "true");
	var initdoneUix = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneUix") == "true");
	var initdoneComp = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneComp") == "true");
	var initdoneJob = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneJob") == "true");
	var initdoneDeploy = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneDeploy") == "true");
	var initdoneAppdev = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneAppdev") == "true");
	var initdoneAuxfct = (retrieveSi(srcdoc, "StatAppWznmNav", "initdoneAuxfct") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlWznmNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdonePre) {
		doc.getElementById("Pre").src = "./PnlWznmNavPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlWznmNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneGlobal) {
		doc.getElementById("Global").src = "./PnlWznmNavGlobal.html?scrJref=" + scrJrefGlobal;
	} else if (!initdoneProject) {
		doc.getElementById("Project").src = "./PnlWznmNavProject.html?scrJref=" + scrJrefProject;
	} else if (!initdoneDbstr) {
		doc.getElementById("Dbstr").src = "./PnlWznmNavDbstr.html?scrJref=" + scrJrefDbstr;
	} else if (!initdoneUix) {
		doc.getElementById("Uix").src = "./PnlWznmNavUix.html?scrJref=" + scrJrefUix;
	} else if (!initdoneComp) {
		doc.getElementById("Comp").src = "./PnlWznmNavComp.html?scrJref=" + scrJrefComp;
	} else if (!initdoneJob) {
		doc.getElementById("Job").src = "./PnlWznmNavJob.html?scrJref=" + scrJrefJob;
	} else if (!initdoneDeploy) {
		doc.getElementById("Deploy").src = "./PnlWznmNavDeploy.html?scrJref=" + scrJrefDeploy;
	} else if (!initdoneAppdev) {
		doc.getElementById("Appdev").src = "./PnlWznmNavAppdev.html?scrJref=" + scrJrefAppdev;
	} else if (!initdoneAuxfct) {
		doc.getElementById("Auxfct").src = "./PnlWznmNavAuxfct.html?scrJref=" + scrJrefAuxfct;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trPre").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdPre").getAttribute("height"));
	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trGlobal").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdGlobal").getAttribute("height")) + 8;
	if (doc.getElementById("trProject").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdProject").getAttribute("height")) + 8;
	if (doc.getElementById("trDbstr").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdDbstr").getAttribute("height")) + 8;
	if (doc.getElementById("trUix").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdUix").getAttribute("height")) + 8;
	if (doc.getElementById("trComp").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdComp").getAttribute("height")) + 8;
	if (doc.getElementById("trJob").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdJob").getAttribute("height")) + 8;
	if (doc.getElementById("trDeploy").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdDeploy").getAttribute("height")) + 8;
	if (doc.getElementById("trAppdev").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAppdev").getAttribute("height")) + 8;
	if (doc.getElementById("trAuxfct").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAuxfct").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppWznmNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWznmNav", "shortMenu", short);
	setSi(srcdoc, "StatAppWznmNav", "widthMenu", "" + (width-3));

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWznmNav", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspApp2Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspApp2Avail") == "true");
	MitAppMlcAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitAppMlcAvail") == "true");
	MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWznmNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagWznmNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagWznmNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppMlc"), retrieveTi(srcdoc, "TagWznmNav", "MitAppMlc"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagWznmNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppMlc", MitAppMlcAvail, 20);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MitSesSpsAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitSesSpsAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWznmNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfWznmNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfWznmNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfWznmNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesSps"), retrieveTi(srcdoc, "TagWznmNav", "MitSesSps"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagWznmNav", "MitSesTrm"));

	height -= setMitMspAvail("MitSesSps", MitSesSpsAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPrsAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdFilAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd2Avail") == "true");
	MitCrdLocAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdLocAvail") == "true");
	MitCrdTagAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdTagAvail") == "true");
	MitCrdCtpAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCtpAvail") == "true");
	MitCrdMtyAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMtyAvail") == "true");
	MitCrdMchAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMchAvail") == "true");
	MitCrdLibAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdLibAvail") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd3Avail") == "true");
	MitCrdPrjAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPrjAvail") == "true");
	MitCrdVerAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdVerAvail") == "true");
	MitCrdCapAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCapAvail") == "true");
	MitCrdCapActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCapActive") == "true");
	MitCrdErrAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdErrAvail") == "true");
	MitCrdErrActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdErrActive") == "true");
	MspCrd4Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd4Avail") == "true");
	MitCrdTblAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdTblAvail") == "true");
	MitCrdTblActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdTblActive") == "true");
	MitCrdTcoAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdTcoAvail") == "true");
	MitCrdTcoActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdTcoActive") == "true");
	MitCrdSbsAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSbsAvail") == "true");
	MitCrdSbsActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSbsActive") == "true");
	MitCrdRelAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRelAvail") == "true");
	MitCrdRelActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRelActive") == "true");
	MitCrdVecAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdVecAvail") == "true");
	MitCrdVecActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdVecActive") == "true");
	MitCrdVitAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdVitAvail") == "true");
	MitCrdVitActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdVitActive") == "true");
	MitCrdChkAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdChkAvail") == "true");
	MitCrdChkActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdChkActive") == "true");
	MitCrdStbAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdStbAvail") == "true");
	MitCrdStbActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdStbActive") == "true");
	MitCrdIexAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdIexAvail") == "true");
	MitCrdIexActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdIexActive") == "true");
	MitCrdImeAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdImeAvail") == "true");
	MitCrdImeActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdImeActive") == "true");
	MspCrd5Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd5Avail") == "true");
	MitCrdPstAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPstAvail") == "true");
	MitCrdPstActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPstActive") == "true");
	MitCrdMdlAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMdlAvail") == "true");
	MitCrdMdlActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMdlActive") == "true");
	MitCrdCarAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCarAvail") == "true");
	MitCrdCarActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCarActive") == "true");
	MitCrdDlgAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdDlgAvail") == "true");
	MitCrdDlgActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdDlgActive") == "true");
	MitCrdPnlAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPnlAvail") == "true");
	MitCrdPnlActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdPnlActive") == "true");
	MitCrdQryAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQryAvail") == "true");
	MitCrdQryActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQryActive") == "true");
	MitCrdQcoAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQcoAvail") == "true");
	MitCrdQcoActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQcoActive") == "true");
	MitCrdQmdAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQmdAvail") == "true");
	MitCrdQmdActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdQmdActive") == "true");
	MitCrdConAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdConAvail") == "true");
	MitCrdConActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdConActive") == "true");
	MspCrd6Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd6Avail") == "true");
	MitCrdOpkAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdOpkAvail") == "true");
	MitCrdOpkActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdOpkActive") == "true");
	MitCrdOpxAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdOpxAvail") == "true");
	MitCrdOpxActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdOpxActive") == "true");
	MspCrd7Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd7Avail") == "true");
	MitCrdJobAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdJobAvail") == "true");
	MitCrdJobActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdJobActive") == "true");
	MitCrdSgeAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSgeAvail") == "true");
	MitCrdSgeActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSgeActive") == "true");
	MitCrdMtdAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMtdAvail") == "true");
	MitCrdMtdActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdMtdActive") == "true");
	MitCrdBlkAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdBlkAvail") == "true");
	MitCrdBlkActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdBlkActive") == "true");
	MitCrdCalAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCalAvail") == "true");
	MitCrdCalActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCalActive") == "true");
	MspCrd8Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd8Avail") == "true");
	MitCrdCmpAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdCmpAvail") == "true");
	MitCrdRlsAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRlsAvail") == "true");
	MitCrdRlsActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRlsActive") == "true");
	MspCrd9Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd9Avail") == "true");
	MitCrdAppAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdAppAvail") == "true");
	MitCrdRtjAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRtjAvail") == "true");
	MitCrdRtjActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdRtjActive") == "true");
	MitCrdEvtAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdEvtAvail") == "true");
	MitCrdEvtActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdEvtActive") == "true");
	MitCrdSeqAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSeqAvail") == "true");
	MitCrdSeqActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSeqActive") == "true");
	MitCrdSteAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSteAvail") == "true");
	MitCrdSteActive = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdSteActive") == "true");
	MspCrd10Avail = (retrieveSi(srcdoc, "StatShrWznmNav", "MspCrd10Avail") == "true");
	MitCrdUtlAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "MitCrdUtlAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWznmNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdFil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLoc"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdLoc"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdTag"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdTag"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdCtp"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCtp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMty"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdMty"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMch"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdMch"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLib"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdLib"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrj"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdPrj"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdVer"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdVer"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdCap"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCap"));
	setMitActive("MitCrdCap", MitCrdCapActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdErr"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdErr"));
	setMitActive("MitCrdErr", MitCrdErrActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdTbl"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdTbl"));
	setMitActive("MitCrdTbl", MitCrdTblActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdTco"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdTco"));
	setMitActive("MitCrdTco", MitCrdTcoActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSbs"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdSbs"));
	setMitActive("MitCrdSbs", MitCrdSbsActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdRel"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdRel"));
	setMitActive("MitCrdRel", MitCrdRelActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdVec"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdVec"));
	setMitActive("MitCrdVec", MitCrdVecActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdVit"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdVit"));
	setMitActive("MitCrdVit", MitCrdVitActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdChk"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdChk"));
	setMitActive("MitCrdChk", MitCrdChkActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdStb"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdStb"));
	setMitActive("MitCrdStb", MitCrdStbActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIex"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdIex"));
	setMitActive("MitCrdIex", MitCrdIexActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIme"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdIme"));
	setMitActive("MitCrdIme", MitCrdImeActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdPst"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdPst"));
	setMitActive("MitCrdPst", MitCrdPstActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdMdl"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdMdl"));
	setMitActive("MitCrdMdl", MitCrdMdlActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCar"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCar"));
	setMitActive("MitCrdCar", MitCrdCarActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdDlg"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdDlg"));
	setMitActive("MitCrdDlg", MitCrdDlgActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdPnl"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdPnl"));
	setMitActive("MitCrdPnl", MitCrdPnlActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdQry"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdQry"));
	setMitActive("MitCrdQry", MitCrdQryActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdQco"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdQco"));
	setMitActive("MitCrdQco", MitCrdQcoActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdQmd"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdQmd"));
	setMitActive("MitCrdQmd", MitCrdQmdActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCon"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCon"));
	setMitActive("MitCrdCon", MitCrdConActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdOpk"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdOpk"));
	setMitActive("MitCrdOpk", MitCrdOpkActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdOpx"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdOpx"));
	setMitActive("MitCrdOpx", MitCrdOpxActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdJob"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdJob"));
	setMitActive("MitCrdJob", MitCrdJobActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSge"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdSge"));
	setMitActive("MitCrdSge", MitCrdSgeActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdMtd"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdMtd"));
	setMitActive("MitCrdMtd", MitCrdMtdActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdBlk"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdBlk"));
	setMitActive("MitCrdBlk", MitCrdBlkActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCal"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCal"));
	setMitActive("MitCrdCal", MitCrdCalActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCmp"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdCmp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdRls"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdRls"));
	setMitActive("MitCrdRls", MitCrdRlsActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdApp"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdApp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdRtj"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdRtj"));
	setMitActive("MitCrdRtj", MitCrdRtjActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdEvt"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdEvt"));
	setMitActive("MitCrdEvt", MitCrdEvtActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSeq"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdSeq"));
	setMitActive("MitCrdSeq", MitCrdSeqActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSte"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdSte"));
	setMitActive("MitCrdSte", MitCrdSteActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdUtl"), retrieveTi(srcdoc, "TagWznmNav", "MitCrdUtl"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdLoc", MitCrdLocAvail, 20);
	height -= setMitMspAvail("MitCrdTag", MitCrdTagAvail, 20);
	height -= setMitMspAvail("MitCrdCtp", MitCrdCtpAvail, 20);
	height -= setMitMspAvail("MitCrdMty", MitCrdMtyAvail, 20);
	height -= setMitMspAvail("MitCrdMch", MitCrdMchAvail, 20);
	height -= setMitMspAvail("MitCrdLib", MitCrdLibAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdPrj", MitCrdPrjAvail, 20);
	height -= setMitMspAvail("MitCrdVer", MitCrdVerAvail, 20);
	height -= setMitMspAvail("MitCrdCap", MitCrdCapAvail, 20);
	height -= setMitMspAvail("MitCrdErr", MitCrdErrAvail, 20);
	height -= setMitMspAvail("MspCrd4", MspCrd4Avail, 1);
	height -= setMitMspAvail("MitCrdTbl", MitCrdTblAvail, 20);
	height -= setMitMspAvail("MitCrdTco", MitCrdTcoAvail, 20);
	height -= setMitMspAvail("MitCrdSbs", MitCrdSbsAvail, 20);
	height -= setMitMspAvail("MitCrdRel", MitCrdRelAvail, 20);
	height -= setMitMspAvail("MitCrdVec", MitCrdVecAvail, 20);
	height -= setMitMspAvail("MitCrdVit", MitCrdVitAvail, 20);
	height -= setMitMspAvail("MitCrdChk", MitCrdChkAvail, 20);
	height -= setMitMspAvail("MitCrdStb", MitCrdStbAvail, 20);
	height -= setMitMspAvail("MitCrdIex", MitCrdIexAvail, 20);
	height -= setMitMspAvail("MitCrdIme", MitCrdImeAvail, 20);
	height -= setMitMspAvail("MspCrd5", MspCrd5Avail, 1);
	height -= setMitMspAvail("MitCrdPst", MitCrdPstAvail, 20);
	height -= setMitMspAvail("MitCrdMdl", MitCrdMdlAvail, 20);
	height -= setMitMspAvail("MitCrdCar", MitCrdCarAvail, 20);
	height -= setMitMspAvail("MitCrdDlg", MitCrdDlgAvail, 20);
	height -= setMitMspAvail("MitCrdPnl", MitCrdPnlAvail, 20);
	height -= setMitMspAvail("MitCrdQry", MitCrdQryAvail, 20);
	height -= setMitMspAvail("MitCrdQco", MitCrdQcoAvail, 20);
	height -= setMitMspAvail("MitCrdQmd", MitCrdQmdAvail, 20);
	height -= setMitMspAvail("MitCrdCon", MitCrdConAvail, 20);
	height -= setMitMspAvail("MspCrd6", MspCrd6Avail, 1);
	height -= setMitMspAvail("MitCrdOpk", MitCrdOpkAvail, 20);
	height -= setMitMspAvail("MitCrdOpx", MitCrdOpxAvail, 20);
	height -= setMitMspAvail("MspCrd7", MspCrd7Avail, 1);
	height -= setMitMspAvail("MitCrdJob", MitCrdJobAvail, 20);
	height -= setMitMspAvail("MitCrdSge", MitCrdSgeAvail, 20);
	height -= setMitMspAvail("MitCrdMtd", MitCrdMtdAvail, 20);
	height -= setMitMspAvail("MitCrdBlk", MitCrdBlkAvail, 20);
	height -= setMitMspAvail("MitCrdCal", MitCrdCalAvail, 20);
	height -= setMitMspAvail("MspCrd8", MspCrd8Avail, 1);
	height -= setMitMspAvail("MitCrdCmp", MitCrdCmpAvail, 20);
	height -= setMitMspAvail("MitCrdRls", MitCrdRlsAvail, 20);
	height -= setMitMspAvail("MspCrd9", MspCrd9Avail, 1);
	height -= setMitMspAvail("MitCrdApp", MitCrdAppAvail, 20);
	height -= setMitMspAvail("MitCrdRtj", MitCrdRtjAvail, 20);
	height -= setMitMspAvail("MitCrdEvt", MitCrdEvtAvail, 20);
	height -= setMitMspAvail("MitCrdSeq", MitCrdSeqAvail, 20);
	height -= setMitMspAvail("MitCrdSte", MitCrdSteAvail, 20);
	height -= setMitMspAvail("MspCrd10", MspCrd10Avail, 1);
	height -= setMitMspAvail("MitCrdUtl", MitCrdUtlAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgWznmNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfWznmAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfWznmAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfWznmAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Global") {
		doc.getElementById("tdGlobal").setAttribute("height", "" + height);
		doc.getElementById("Global").setAttribute("height", "" + height);
	} else if (pnlshort == "Project") {
		doc.getElementById("tdProject").setAttribute("height", "" + height);
		doc.getElementById("Project").setAttribute("height", "" + height);
	} else if (pnlshort == "Dbstr") {
		doc.getElementById("tdDbstr").setAttribute("height", "" + height);
		doc.getElementById("Dbstr").setAttribute("height", "" + height);
	} else if (pnlshort == "Uix") {
		doc.getElementById("tdUix").setAttribute("height", "" + height);
		doc.getElementById("Uix").setAttribute("height", "" + height);
	} else if (pnlshort == "Comp") {
		doc.getElementById("tdComp").setAttribute("height", "" + height);
		doc.getElementById("Comp").setAttribute("height", "" + height);
	} else if (pnlshort == "Job") {
		doc.getElementById("tdJob").setAttribute("height", "" + height);
		doc.getElementById("Job").setAttribute("height", "" + height);
	} else if (pnlshort == "Deploy") {
		doc.getElementById("tdDeploy").setAttribute("height", "" + height);
		doc.getElementById("Deploy").setAttribute("height", "" + height);
	} else if (pnlshort == "Appdev") {
		doc.getElementById("tdAppdev").setAttribute("height", "" + height);
		doc.getElementById("Appdev").setAttribute("height", "" + height);
	} else if (pnlshort == "Auxfct") {
		doc.getElementById("tdAuxfct").setAttribute("height", "" + height);
		doc.getElementById("Auxfct").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefDlgloaini");
	var scrJrefDlgmnglic = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefDlgmnglic");
	var pnlpreAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlpreAvail") == "true");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnladminAvail") == "true");
	var pnlglobalAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlglobalAvail") == "true");
	var pnlprojectAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlprojectAvail") == "true");
	var pnldbstrAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnldbstrAvail") == "true");
	var pnluixAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnluixAvail") == "true");
	var pnlcompAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlcompAvail") == "true");
	var pnljobAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnljobAvail") == "true");
	var pnldeployAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnldeployAvail") == "true");
	var pnlappdevAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlappdevAvail") == "true");
	var pnlauxfctAvail = (retrieveSi(srcdoc, "StatShrWznmNav", "pnlauxfctAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgWznmNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlgmnglic != "") {
		if (scrJrefDlg != scrJrefDlgmnglic) showDlg("DlgWznmNavMnglic", scrJrefDlgmnglic);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Pre", pnlpreAvail);
	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Global", pnlglobalAvail);
	setPnlAvail("Project", pnlprojectAvail);
	setPnlAvail("Dbstr", pnldbstrAvail);
	setPnlAvail("Uix", pnluixAvail);
	setPnlAvail("Comp", pnlcompAvail);
	setPnlAvail("Job", pnljobAvail);
	setPnlAvail("Deploy", pnldeployAvail);
	setPnlAvail("Appdev", pnlappdevAvail);
	setPnlAvail("Auxfct", pnlauxfctAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfWznmNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmNavData", "ContInfWznmNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngWznmNavData", "StatAppWznmNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmNavData", "StatShrWznmNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmNavData", "TagWznmNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefPre) {
		doc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAdmin) {
		doc.getElementById("Admin").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefGlobal) {
		doc.getElementById("Global").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefProject) {
		doc.getElementById("Project").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefDbstr) {
		doc.getElementById("Dbstr").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefUix) {
		doc.getElementById("Uix").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefComp) {
		doc.getElementById("Comp").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefJob) {
		doc.getElementById("Job").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefDeploy) {
		doc.getElementById("Deploy").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAppdev) {
		doc.getElementById("Appdev").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAuxfct) {
		doc.getElementById("Auxfct").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWznmNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefHeadbar");
				scrJrefPre = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefPre");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefAdmin");
				scrJrefGlobal = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefGlobal");
				scrJrefProject = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefProject");
				scrJrefDbstr = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefDbstr");
				scrJrefUix = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefUix");
				scrJrefComp = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefComp");
				scrJrefJob = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefJob");
				scrJrefDeploy = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefDeploy");
				scrJrefAppdev = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefAppdev");
				scrJrefAuxfct = retrieveSi(srcdoc, "StatShrWznmNav", "scrJrefAuxfct");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var _scrJref;

	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");

			if (_scrJref != "") {
				if (_scrJref == scrJref) {
					if (blk.nodeName == "DpchEngWznmConfirm") {
						// do nothing

					} else if (blk.nodeName == "DpchEngWznmAlert") {
						// show alert with new content
						showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
								retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
								retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));

					} else if (blk.nodeName == "DpchEngWznmNavData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
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
				showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
						retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("../CrdWznmStart/CrdWznmStart.html?do=Logout", "_self");
};

function restartNotify() {
	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmNav", "srefIxWznmVReqitmode");

	if (srefIxWznmVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxWznmVReqitmode = "notify";
		setSi(srcdoc, "StatAppWznmNav", "srefIxWznmVReqitmode", srefIxWznmVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmNav", "srefIxWznmVReqitmode");

	if (srefIxWznmVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppWznmResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) if (blk.nodeName == "DpchEngWznmAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmNav", "srefIxWznmVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppWznmNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//wznm:*");

			if (blk) {
				if (blk.nodeName == "DpchEngWznmAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngWznmSuspend") {
					// change to "poll" mode
					news = true;

					srefIxWznmVReqitmode = "poll";
					setSi(srcdoc, "StatAppWznmNav", "srefIxWznmVReqitmode", srefIxWznmVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");

					if (blk.nodeName == "DpchEngWznmAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//wznm:DpchEngWznmAlert/wznm:scrJref"),
								retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:ContInfWznmAlert"),
								retrieveBlock(dom, "//wznm:DpchEngWznmAlert/wznm:FeedFMcbAlert"));

					} else if (_scrJref != "") {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngWznmConfirm") {
								accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngWznmNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
					};
				};
			};
		};
	};

	if ((srefIxWznmVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxWznmVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};

