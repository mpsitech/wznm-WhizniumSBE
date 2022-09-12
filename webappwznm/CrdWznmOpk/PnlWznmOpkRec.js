function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefDetail");
	scrJrefARetval = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefARetval");
	scrJrefAInvarg = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefAInvarg");
	scrJref1NOp = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJref1NOp");
	scrJrefRef1NBlock = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefRef1NBlock");
	scrJrefMNJob = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefMNJob");
	scrJrefMNComponent = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefMNComponent");
	scrJrefMNLibrary = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefMNLibrary");
	scrJrefSqkMNStub = retrieveSi(srcdoc, "StatShrWznmOpkRec", "scrJrefSqkMNStub");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneARetval", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneAInvarg", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdone1NOp", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneRef1NBlock", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNJob", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNComponent", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNLibrary", "false");
	setSi(srcdoc, "StatAppWznmOpkRec", "initdoneSqkMNStub", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightARetval = 30;
	heightAInvarg = 30;
	height1NOp = 30;
	heightRef1NBlock = 30;
	heightMNJob = 30;
	heightMNComponent = 30;
	heightMNLibrary = 30;
	heightSqkMNStub = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmOpkRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneDetail") == "true");
	var initdoneARetval = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneARetval") == "true");
	var initdoneAInvarg = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneAInvarg") == "true");
	var initdone1NOp = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdone1NOp") == "true");
	var initdoneRef1NBlock = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneRef1NBlock") == "true");
	var initdoneMNJob = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNJob") == "true");
	var initdoneMNComponent = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNComponent") == "true");
	var initdoneMNLibrary = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneMNLibrary") == "true");
	var initdoneSqkMNStub = (retrieveSi(srcdoc, "StatAppWznmOpkRec", "initdoneSqkMNStub") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmOpkDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneARetval) {
		lhsdoc.getElementById("ARetval").src = "./PnlWznmOpkARetval.html?scrJref=" + scrJrefARetval;
	} else if (!initdoneAInvarg) {
		lhsdoc.getElementById("AInvarg").src = "./PnlWznmOpkAInvarg.html?scrJref=" + scrJrefAInvarg;
	} else if (!initdone1NOp) {
		rhsdoc.getElementById("1NOp").src = "./PnlWznmOpk1NOp.html?scrJref=" + scrJref1NOp;
	} else if (!initdoneRef1NBlock) {
		rhsdoc.getElementById("Ref1NBlock").src = "./PnlWznmOpkRef1NBlock.html?scrJref=" + scrJrefRef1NBlock;
	} else if (!initdoneMNJob) {
		rhsdoc.getElementById("MNJob").src = "./PnlWznmOpkMNJob.html?scrJref=" + scrJrefMNJob;
	} else if (!initdoneMNComponent) {
		rhsdoc.getElementById("MNComponent").src = "./PnlWznmOpkMNComponent.html?scrJref=" + scrJrefMNComponent;
	} else if (!initdoneMNLibrary) {
		rhsdoc.getElementById("MNLibrary").src = "./PnlWznmOpkMNLibrary.html?scrJref=" + scrJrefMNLibrary;
	} else if (!initdoneSqkMNStub) {
		rhsdoc.getElementById("SqkMNStub").src = "./PnlWznmOpkSqkMNStub.html?scrJref=" + scrJrefSqkMNStub;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "ARetval") || (short == "AInvarg")) lhsrhsdoc = lhsdoc;
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
		else if (short == "ARetval") heightARetval = height;
		else if (short == "AInvarg") heightAInvarg = height;
		else if (short == "1NOp") height1NOp = height;
		else if (short == "Ref1NBlock") heightRef1NBlock = height;
		else if (short == "MNJob") heightMNJob = height;
		else if (short == "MNComponent") heightMNComponent = height;
		else if (short == "MNLibrary") heightMNLibrary = height;
		else if (short == "SqkMNStub") heightSqkMNStub = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmOpkRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmOpkRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 309);
	doc.getElementById("tdSide").setAttribute("height", "309");
	doc.getElementById("Rec_side").setAttribute("height", "309");
	doc.getElementById("Rec_cont").setAttribute("height", "309");

	doc.getElementById("Rec_side").src = "./PnlWznmOpkRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmOpkRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "ARetval") || (pnlshort == "AInvarg")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "ARetval") heightARetval = height;
	else if (pnlshort == "AInvarg") heightAInvarg = height;
	else if (pnlshort == "1NOp") height1NOp = height;
	else if (pnlshort == "Ref1NBlock") heightRef1NBlock = height;
	else if (pnlshort == "MNJob") heightMNJob = height;
	else if (pnlshort == "MNComponent") heightMNComponent = height;
	else if (pnlshort == "MNLibrary") heightMNLibrary = height;
	else if (pnlshort == "SqkMNStub") heightSqkMNStub = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightARetval+13 + heightAInvarg+13 + 5;
	heightRhs = height1NOp+13 + heightRef1NBlock+13 + heightMNJob+13 + heightMNComponent+13 + heightMNLibrary+13 + heightSqkMNStub+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmOpkRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmOpkRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmOpkRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmOpkRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlsqkmnstubAvail = (retrieveSi(srcdoc, "StatShrWznmOpkRec", "pnlsqkmnstubAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmOpkRec", "TxtRef"));

	if (setPnlAvail("SqkMNStub", pnlsqkmnstubAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmOpkRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmOpkRecData", "ContInfWznmOpkRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmOpkRecData", "StatAppWznmOpkRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmOpkRecData", "StatShrWznmOpkRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmOpkRecData", "TagWznmOpkRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmOpkRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefARetval) {
				if (getInitdone("ARetval")) lhsdoc.getElementById("ARetval").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAInvarg) {
				if (getInitdone("AInvarg")) lhsdoc.getElementById("AInvarg").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NOp) {
				if (getInitdone("1NOp")) rhsdoc.getElementById("1NOp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NBlock) {
				if (getInitdone("Ref1NBlock")) rhsdoc.getElementById("Ref1NBlock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNJob) {
				if (getInitdone("MNJob")) rhsdoc.getElementById("MNJob").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNComponent) {
				if (getInitdone("MNComponent")) rhsdoc.getElementById("MNComponent").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLibrary) {
				if (getInitdone("MNLibrary")) rhsdoc.getElementById("MNLibrary").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSqkMNStub) {
				if (getInitdone("SqkMNStub")) rhsdoc.getElementById("SqkMNStub").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmOpkRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmOpkRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmOpkRec", "srefIxWznmVExpstate");

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
