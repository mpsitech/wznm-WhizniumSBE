function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmVer", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmVer", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppWznmVer", "initdoneHeadbar") == "true");
	var initdoneList = (retrieveSi(srcdoc, "StatAppWznmVer", "initdoneList") == "true");
	var initdoneRec = (retrieveSi(srcdoc, "StatAppWznmVer", "initdoneRec") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlWznmVerHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdoneList) {
		doc.getElementById("List").src = "./PnlWznmVerList.html?scrJref=" + scrJrefList;
	} else if (!initdoneRec) {
		doc.getElementById("Rec").src = "./PnlWznmVerRec.html?scrJref=" + scrJrefRec;
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

	height += 10 + parseInt(doc.getElementById("tdList").getAttribute("height")) + 8;
	height += 10 + parseInt(doc.getElementById("tdRec").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppWznmVer", "shortMenu");

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

	setSi(srcdoc, "StatAppWznmVer", "shortMenu", short);
	setSi(srcdoc, "StatAppWznmVer", "widthMenu", "" + (width-3));

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

	setSi(srcdoc, "StatAppWznmVer", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWznmVer", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagWznmVer", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagWznmVer", "MrlAppHlp"));
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd1Avail") == "true");
	MitCrdNewAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdNewAvail") == "true");
	MitCrdPcvAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdPcvAvail") == "true");
	MitCrdPcvActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdPcvActive") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd3Avail") == "true");
	MitCrdIdpAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIdpAvail") == "true");
	MitCrdIdpActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIdpActive") == "true");
	MitCrdIgbAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIgbAvail") == "true");
	MitCrdIgbActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIgbActive") == "true");
	MspCrd4Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd4Avail") == "true");
	MitCrdImdAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdImdAvail") == "true");
	MitCrdImdActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdImdActive") == "true");
	MspCrd5Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd5Avail") == "true");
	MitCrdIdbAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIdbAvail") == "true");
	MitCrdIdbActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIdbActive") == "true");
	MitCrdIbuAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIbuAvail") == "true");
	MitCrdIbuActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIbuActive") == "true");
	MitCrdIieAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIieAvail") == "true");
	MitCrdIieActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIieActive") == "true");
	MitCrdIopAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIopAvail") == "true");
	MitCrdIopActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIopActive") == "true");
	MitCrdIcjAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIcjAvail") == "true");
	MitCrdIcjActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdIcjActive") == "true");
	MspCrd6Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd6Avail") == "true");
	MitCrdGuiAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdGuiAvail") == "true");
	MitCrdGuiActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdGuiActive") == "true");
	MitCrdAuiAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdAuiAvail") == "true");
	MitCrdAuiActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdAuiActive") == "true");
	MitCrdGjtAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdGjtAvail") == "true");
	MitCrdGjtActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdGjtActive") == "true");
	MitCrdAjtAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdAjtAvail") == "true");
	MitCrdAjtActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdAjtActive") == "true");
	MspCrd7Avail = (retrieveSi(srcdoc, "StatShrWznmVer", "MspCrd7Avail") == "true");
	MitCrdFnmAvail = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdFnmAvail") == "true");
	MitCrdFnmActive = (retrieveSi(srcdoc, "StatShrWznmVer", "MitCrdFnmActive") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWznmVer", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxCrdVer"), retrieveCi(srcdoc, "ContInfWznmVer", "MtxCrdVer"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdNew"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdNew"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPcv"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdPcv"));
	setMitActive("MitCrdPcv", MitCrdPcvActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIdp"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIdp"));
	setMitActive("MitCrdIdp", MitCrdIdpActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIgb"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIgb"));
	setMitActive("MitCrdIgb", MitCrdIgbActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdImd"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdImd"));
	setMitActive("MitCrdImd", MitCrdImdActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIdb"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIdb"));
	setMitActive("MitCrdIdb", MitCrdIdbActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIbu"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIbu"));
	setMitActive("MitCrdIbu", MitCrdIbuActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIie"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIie"));
	setMitActive("MitCrdIie", MitCrdIieActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIop"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIop"));
	setMitActive("MitCrdIop", MitCrdIopActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdIcj"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdIcj"));
	setMitActive("MitCrdIcj", MitCrdIcjActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdGui"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdGui"));
	setMitActive("MitCrdGui", MitCrdGuiActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdAui"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdAui"));
	setMitActive("MitCrdAui", MitCrdAuiActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdGjt"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdGjt"));
	setMitActive("MitCrdGjt", MitCrdGjtActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdAjt"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdAjt"));
	setMitActive("MitCrdAjt", MitCrdAjtActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdFnm"), retrieveTi(srcdoc, "TagWznmVer", "MitCrdFnm"));
	setMitActive("MitCrdFnm", MitCrdFnmActive);

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdNew", MitCrdNewAvail, 20);
	height -= setMitMspAvail("MitCrdPcv", MitCrdPcvAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdIdp", MitCrdIdpAvail, 20);
	height -= setMitMspAvail("MitCrdIgb", MitCrdIgbAvail, 20);
	height -= setMitMspAvail("MspCrd4", MspCrd4Avail, 1);
	height -= setMitMspAvail("MitCrdImd", MitCrdImdAvail, 20);
	height -= setMitMspAvail("MspCrd5", MspCrd5Avail, 1);
	height -= setMitMspAvail("MitCrdIdb", MitCrdIdbAvail, 20);
	height -= setMitMspAvail("MitCrdIbu", MitCrdIbuAvail, 20);
	height -= setMitMspAvail("MitCrdIie", MitCrdIieAvail, 20);
	height -= setMitMspAvail("MitCrdIop", MitCrdIopAvail, 20);
	height -= setMitMspAvail("MitCrdIcj", MitCrdIcjAvail, 20);
	height -= setMitMspAvail("MspCrd6", MspCrd6Avail, 1);
	height -= setMitMspAvail("MitCrdGui", MitCrdGuiAvail, 20);
	height -= setMitMspAvail("MitCrdAui", MitCrdAuiAvail, 20);
	height -= setMitMspAvail("MitCrdGjt", MitCrdGjtAvail, 20);
	height -= setMitMspAvail("MitCrdAjt", MitCrdAjtAvail, 20);
	height -= setMitMspAvail("MspCrd7", MspCrd7Avail, 1);
	height -= setMitMspAvail("MitCrdFnm", MitCrdFnmAvail, 20);

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

	doc.getElementById("Rec").contentWindow.reinitPnl(scrJrefPnld);

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
	if ((sref == "DlgWznmVerDeploy") || (sref == "DlgWznmVerGlobal") || (sref == "DlgWznmVerWrinimdl") || (sref == "DlgWznmVerDbstr") || (sref == "DlgWznmVerBscui") || (sref == "DlgWznmVerImpexp") || (sref == "DlgWznmVerOppack") || (sref == "DlgWznmVerCustjob") || (sref == "DlgWznmVerGenui") || (sref == "DlgWznmVerCustui") || (sref == "DlgWznmVerGenjtr") || (sref == "DlgWznmVerCustjtr")) myif.setAttribute("height", "585");
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

	if (pnlshort == "List") {
		doc.getElementById("tdList").setAttribute("height", "" + height);
		doc.getElementById("List").setAttribute("height", "" + height);
	} else if (pnlshort == "Rec") {
		doc.getElementById("tdRec").setAttribute("height", "" + height);
		doc.getElementById("Rec").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgbscui = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgbscui");
	var scrJrefDlgcustjob = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgcustjob");
	var scrJrefDlgcustjtr = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgcustjtr");
	var scrJrefDlgcustui = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgcustui");
	var scrJrefDlgdbstr = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgdbstr");
	var scrJrefDlgdeploy = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgdeploy");
	var scrJrefDlgfinmod = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgfinmod");
	var scrJrefDlggenjtr = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlggenjtr");
	var scrJrefDlggenui = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlggenui");
	var scrJrefDlgglobal = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgglobal");
	var scrJrefDlgimpexp = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgimpexp");
	var scrJrefDlgnew = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgnew");
	var scrJrefDlgoppack = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgoppack");
	var scrJrefDlgwrinimdl = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefDlgwrinimdl");

	if (scrJrefDlgbscui != "") {
		if (scrJrefDlg != scrJrefDlgbscui) showDlg("DlgWznmVerBscui", scrJrefDlgbscui);
	} else if (scrJrefDlgcustjob != "") {
		if (scrJrefDlg != scrJrefDlgcustjob) showDlg("DlgWznmVerCustjob", scrJrefDlgcustjob);
	} else if (scrJrefDlgcustjtr != "") {
		if (scrJrefDlg != scrJrefDlgcustjtr) showDlg("DlgWznmVerCustjtr", scrJrefDlgcustjtr);
	} else if (scrJrefDlgcustui != "") {
		if (scrJrefDlg != scrJrefDlgcustui) showDlg("DlgWznmVerCustui", scrJrefDlgcustui);
	} else if (scrJrefDlgdbstr != "") {
		if (scrJrefDlg != scrJrefDlgdbstr) showDlg("DlgWznmVerDbstr", scrJrefDlgdbstr);
	} else if (scrJrefDlgdeploy != "") {
		if (scrJrefDlg != scrJrefDlgdeploy) showDlg("DlgWznmVerDeploy", scrJrefDlgdeploy);
	} else if (scrJrefDlgfinmod != "") {
		if (scrJrefDlg != scrJrefDlgfinmod) showDlg("DlgWznmVerFinmod", scrJrefDlgfinmod);
	} else if (scrJrefDlggenjtr != "") {
		if (scrJrefDlg != scrJrefDlggenjtr) showDlg("DlgWznmVerGenjtr", scrJrefDlggenjtr);
	} else if (scrJrefDlggenui != "") {
		if (scrJrefDlg != scrJrefDlggenui) showDlg("DlgWznmVerGenui", scrJrefDlggenui);
	} else if (scrJrefDlgglobal != "") {
		if (scrJrefDlg != scrJrefDlgglobal) showDlg("DlgWznmVerGlobal", scrJrefDlgglobal);
	} else if (scrJrefDlgimpexp != "") {
		if (scrJrefDlg != scrJrefDlgimpexp) showDlg("DlgWznmVerImpexp", scrJrefDlgimpexp);
	} else if (scrJrefDlgnew != "") {
		if (scrJrefDlg != scrJrefDlgnew) showDlg("DlgWznmVerNew", scrJrefDlgnew);
	} else if (scrJrefDlgoppack != "") {
		if (scrJrefDlg != scrJrefDlgoppack) showDlg("DlgWznmVerOppack", scrJrefDlgoppack);
	} else if (scrJrefDlgwrinimdl != "") {
		if (scrJrefDlg != scrJrefDlgwrinimdl) showDlg("DlgWznmVerWrinimdl", scrJrefDlgwrinimdl);
	} else if (scrJrefDlg != "") hideDlg();

	doc.title = retrieveCi(srcdoc, "ContInfWznmVer", "MtxCrdVer") + " - WhizniumSBE v1.1.5";
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfWznmVer", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVerData", "ContInfWznmVer", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVerData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngWznmVerData", "StatAppWznmVer", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVerData", "StatShrWznmVer", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVerData", "TagWznmVer", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefList) {
		doc.getElementById("List").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// scrJrefRec or scrJref of one of its sub-panels
		doc.getElementById("Rec").contentWindow.handleDpchEng(dom, dpch);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWznmVerData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefHeadbar");
				scrJrefList = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefList");
				scrJrefRec = retrieveSi(srcdoc, "StatShrWznmVer", "scrJrefRec");

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

					} else if (blk.nodeName == "DpchEngWznmVerData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("about:blank", "_self");
};

function restartNotify() {
	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmVer", "srefIxWznmVReqitmode");

	if (srefIxWznmVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxWznmVReqitmode = "notify";
		setSi(srcdoc, "StatAppWznmVer", "srefIxWznmVReqitmode", srefIxWznmVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmVer", "srefIxWznmVReqitmode");

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

	var srefIxWznmVReqitmode = retrieveSi(srcdoc, "StatAppWznmVer", "srefIxWznmVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppWznmVer", "latency"));

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
					setSi(srcdoc, "StatAppWznmVer", "srefIxWznmVReqitmode", srefIxWznmVReqitmode);

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

							} else if (blk.nodeName == "DpchEngWznmVerData") {
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
