/**
  * \file CrdWznmStart.js
  * web client functionality for Wznm start page
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

function initLogin() {
	doc.getElementById("tdCont").setAttribute("height", "128");
	doc.getElementById("Cont").setAttribute("height", "120");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxWznmVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptLogin"));
	refreshPup(contdoc, srcdoc, "PupLocale", "", "FeedFPupLoginLocale." + srefIxWznmVLocale, retrieveCi(srcdoc, "Cont", "numFPupLoginLocale"), true, false);
	initCpt(contdoc, "CptUsername", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptLoginUsername"));
	initCpt(contdoc, "CptPassword", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptLoginPassword"));
	initBut(contdoc, "ButReset", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButLoginReset"));
	initBut(contdoc, "ButLogin", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButLoginLogin"));

	refreshLogin();
};

function initSuccess() {
	doc.getElementById("tdCont").setAttribute("height", "172");
	doc.getElementById("Cont").setAttribute("height", "164");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxWznmVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptSuccess"));
	initCpt(contdoc, "CptSuspsess", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptSuccessSuspsess"));
	initBut(contdoc, "ButSuspsessResume", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButSuccessSuspsessResume"));
	initBut(contdoc, "ButBack", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButSuccessBack"));
	initBut(contdoc, "ButNewsess", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButSuccessNewsess"));

	refreshSuccess();
};

function initFailure() {
	doc.getElementById("tdCont").setAttribute("height", "103");
	doc.getElementById("Cont").setAttribute("height", "95");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxWznmVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptFailure"));
	initCpt(contdoc, "CptMessage", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptFailureMessage"));
	initBut(contdoc, "ButBack", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButFailureBack"));
};

function initLogout() {
	doc.getElementById("tdCont").setAttribute("height", "103");
	doc.getElementById("Cont").setAttribute("height", "95");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxWznmVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptLogout"));
	initCpt(contdoc, "CptMessage", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "CptLogoutMessage"));
	initBut(contdoc, "ButLogin", retrieveTi(srcdoc, "Tag." + srefIxWznmVLocale, "ButLogoutLogin"));
};

function refreshLogin() {
	var username = retrieveCi(srcdoc, "Cont", "TxfLoginUsername");
	var password = retrieveCi(srcdoc, "Cont", "TxfLoginPassword");

	refreshTxf(contdoc, "TxfUsername", "", username, true, false, true);
	refreshTxf(contdoc, "TxfPassword", "", password, true, false, true);

	refreshBut(contdoc, "ButReset", (username != "") || (password != ""), false);
	refreshBut(contdoc, "ButLogin", (username != "") && (password != ""), false);
};

function refreshSuccess() {
	var numFLstSuccessSuspsess = parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"));

	refreshLst(contdoc.getElementById("LstSuspsess").contentWindow.document, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [numFLstSuccessSuspsess]);

	refreshBut(contdoc, "ButSuspsessResume", (numFLstSuccessSuspsess != 0), false);
};

function handleLoad() {
	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	if (doc.cookie) {
		var ss = doc.cookie.split(";");

		for (var i = 0; i < ss.length; i++) {
			if (ss[i].search("srefIxWznmVLocale=") == 0) {
				var numFPupLoginLocale = retrieveFeedNumBySref(srcdoc, "FeedFPupLoginLocale.enus", ss[i].substr(18));
				if (!isNaN(numFPupLoginLocale)) setCi(srcdoc, "Cont", "numFPupLoginLocale", "" + numFPupLoginLocale);
				break;
			};
		};
	};

	// determine panel to display from URL
	doc.pnlshort = "Login";
	if (window.location.search.indexOf("do=") != -1) {
		doc.pnlshort = window.location.search.substr(window.location.search.indexOf("do=")+3);
		if ( (doc.pnlshort != "Success") && (doc.pnlshort != "Failure") && (doc.pnlshort != "Logout") ) doc.pnlshort = "Login";
	};

	setCont();
};

function setCont() {
	var resnode;

	if (doc.pnlshort == "Login") {
		setCi(srcdoc, "Cont", "numFLstSuccessSuspsess", "0");
		setCi(srcdoc, "Cont", "TxfLoginUsername", "");
		setCi(srcdoc, "Cont", "TxfLoginPassword", "");

		setSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp", "1");

		resnode = getNode(srcdoc, "//wznm:src/wznm:FeedFEnsSps");
		if (resnode) clearElem(resnode);

		resnode = getNode(srcdoc, "//wznm:src/wznm:FeedFEnsSec");
		if (resnode) clearElem(resnode);
	};

	doc.getElementById("Cont").src = "./PnlWznmStart" + doc.pnlshort + ".xml";
};

function setLocale() {
	// store locale to cookie
	var expdate = new Date();
	var exptime = expdate.getTime() + (30*24*3600*1000);
	expdate.setTime(exptime);

	var srefIxWznmVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	doc.cookie = "srefIxWznmVLocale=" + srefIxWznmVLocale + ";expires=" + expdate.toGMTString();
};

// control handlers for Login
function handlePupLoginLocaleChange() {
	setCi(srcdoc, "Cont", "numFPupLoginLocale", "" + contdoc.getElementById("PupLocale").value);

	setLocale();

	initLogin();
};

function handleTxfLoginUsernameKey(evt) {
	return true;
};

function handleTxfLoginUsernameChange() {
	setCi(srcdoc, "Cont", "TxfLoginUsername", contdoc.getElementById("TxfUsername").value);
	refreshLogin();
};

function handleTxfLoginPasswordKey(evt) {
	if (evt.keyCode == 13) {
		setCi(srcdoc, "Cont", "TxfLoginPassword", contdoc.getElementById("TxfPassword").value);
		handleButLoginLoginClick();

		return false;
	};

	return true;
};

function handleTxfLoginPasswordChange() {
	setCi(srcdoc, "Cont", "TxfLoginPassword", contdoc.getElementById("TxfPassword").value);
	refreshLogin();
};

function handleButLoginResetClick() {
	setCi(srcdoc, "Cont", "TxfLoginUsername", "");
	setCi(srcdoc, "Cont", "TxfLoginPassword", "");

	refreshLogin();
};

function handleButLoginLoginClick() {
	var str = serializeDpchAppLogin(true);
	sendReq(str, doc, handleDpchAppLoginReply);
};

// control handlers for Success
function setLsbSuccessSuspsessPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLstSuccessSuspsessLoad(lstdoc) {
	refreshLst(lstdoc, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"))]);
};

function handleLstSuccessSuspsessSelect(num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	oldNumFLst = parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"));
	if (num == oldNumFLst) num = 0;

	setCi(srcdoc, "Cont", "numFLstSuccessSuspsess", num);

	refreshSuccess();
};

function changeLstSuccessSuspsessNumFirstdisp(lstdoc, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedFEnsSps");

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp", "" + numFirstdisp);

		refreshLst(lstdoc, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"))]);
	};
};

function handleLsbSuccessSuspsessUpClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, -1);
};

function handleLsbSuccessSuspsessJpupClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, -4);
};

function handleLsbSuccessSuspsessJpdownClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, 4);
};

function handleLsbSuccessSuspsessDownClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, 1);
};

function handleLsbSuccessSuspsessMdn(lstdoc) {
	lstdoc.getElementById("tdLsb").onmousemove = contdoc.getElementById("LstSuspsess").contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contdoc.getElementById("LstSuspsess").contentWindow.handleLsbMup;
};

function handleLsbSuccessSuspsessMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbSuccessSuspsessPos(lstdoc, pos);
	};
};

function handleLsbSuccessSuspsessMup(lstdoc, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedFEnsSps");

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, Math.round(pos*(cnt-5))+1, 0);
};

function handleButSuccessSuspsessResumeClick() {
	var scrJref = retrieveFeedSrefByNum(srcdoc, "FeedFEnsSps", parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess")));

	var str = serializeDpchApp("DpchAppWznmInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply);
};

function handleButSuccessBackClick() {
	doc.pnlshort = "Login";
	setCont();
};

function handleButSuccessNewsessClick() {
	var str = serializeDpchAppLogin(false);
	sendReq(str, doc, handleDpchAppLoginReply);
};

// control handlers for Failure
function handleButFailureBackClick() {
	doc.pnlshort = "Login";
	setCont();
};

// control handlers for Logout
function handleButLogoutLoginClick() {
	doc.pnlshort = "Login";
	setCont();
};

// server interaction
function serializeDpchAppLogin(chksuspsess) {
	var dpch, elem;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppRootWznmLogin");

	elem = doc.createElement("username");
	elem.appendChild(getNode(srcdoc, "//wznm:Cont/wznm:Ci[@sref='TxfLoginUsername']").firstChild.cloneNode(true));
	dpch.appendChild(elem);

	elem = doc.createElement("password");
	elem.appendChild(getNode(srcdoc, "//wznm:Cont/wznm:Ci[@sref='TxfLoginPassword']").firstChild.cloneNode(true));
	dpch.appendChild(elem);

	elem = doc.createElement("chksuspsess");
	if (chksuspsess) elem.appendChild(doc.createTextNode("true"));
	else elem.appendChild(doc.createTextNode("false"));
	dpch.appendChild(elem); 

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function handleDpchAppLoginReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWznmConfirm") {
				var accepted = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:accepted");
				if (accepted == "true") {
					var scrJref = retrieveValue(dom, "//wznm:DpchEngWznmConfirm/wznm:scrJref");

					var str = serializeDpchApp("DpchAppWznmInit", scrJref);
					sendReq(str, doc, handleDpchAppInitReply);

				} else {
					doc.pnlshort = "Failure";
					setCont();
				};

			} else if (blk.nodeName == "DpchEngRootWznmData") {
				// chksuspsess = true and login accepted, suspended sessions exist
				updateSrcblock(dom, "DpchEngRootWznmData", "FeedFEnsSps", srcdoc);

				doc.pnlshort = "Success";
				setCont();
			};
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wznm:*");
		if (blk) {
			if (blk.nodeName == "DpchEngSessWznmData") {
				var scrJrefCrdnav = retrieveValue(dom, "//wznm:DpchEngSessWznmData/wznm:StatShrSessWznm/wznm:Si[@sref='scrJrefCrdnav']");

				if (scrJrefCrdnav == "") {
					doc.pnlshort = "Failure";
					setCont();

				} else {
					if (updateSrcblock(dom, "DpchEngSessWznmData", "FeedFEnsSec", srcdoc)) {
						// additional cards may be present for resumed sessions
						var cnt = getFeedSize(srcdoc, "FeedFEnsSec");
						var sref, scrJref;

						for (var i = 1; i <= cnt; i++) {
							sref = retrieveFeedTitleByNumI(srcdoc, "FeedFEnsSec", i, 1);
							scrJref = retrieveFeedSrefByNum(srcdoc, "FeedFEnsSec", i);

							window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + scrJref, "_blank");
						};
					};

					window.open("/web/CrdWznmNav/CrdWznmNav.html?scrJref=" + scrJrefCrdnav, "_parent");
				};
			};
		};
	};
};

