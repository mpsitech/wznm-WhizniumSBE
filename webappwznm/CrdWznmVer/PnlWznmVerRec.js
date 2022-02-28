function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefDetail");
	scrJref1NBlock = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NBlock");
	scrJrefBvr1NVersion = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefBvr1NVersion");
	scrJref1NComponent = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NComponent");
	scrJref1NCall = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NCall");
	scrJref1NImpexpcplx = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NImpexpcplx");
	scrJref1NJob = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NJob");
	scrJref1NOppack = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NOppack");
	scrJrefVer1NModule = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefVer1NModule");
	scrJref1NPreset = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NPreset");
	scrJref1NQuery = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NQuery");
	scrJref1NRelation = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NRelation");
	scrJref1NTable = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NTable");
	scrJref1NVector = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NVector");
	scrJref1NCapability = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJref1NCapability");
	scrJrefVer1NApp = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefVer1NApp");
	scrJrefVer1NError = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefVer1NError");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefRef1NFile");
	scrJrefMNLocale = retrieveSi(srcdoc, "StatShrWznmVerRec", "scrJrefMNLocale");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NBlock", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneBvr1NVersion", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NComponent", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NCall", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NImpexpcplx", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NJob", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NOppack", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NModule", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NPreset", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NQuery", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NRelation", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NTable", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NVector", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdone1NCapability", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NApp", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NError", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppWznmVerRec", "initdoneMNLocale", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NBlock = 30;
	heightBvr1NVersion = 30;
	height1NComponent = 30;
	height1NCall = 30;
	height1NImpexpcplx = 30;
	height1NJob = 30;
	height1NOppack = 30;
	heightVer1NModule = 30;
	height1NPreset = 30;
	height1NQuery = 30;
	height1NRelation = 30;
	height1NTable = 30;
	height1NVector = 30;
	height1NCapability = 30;
	heightVer1NApp = 30;
	heightVer1NError = 30;
	heightRef1NFile = 30;
	heightMNLocale = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmVerRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneDetail") == "true");
	var initdone1NBlock = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NBlock") == "true");
	var initdoneBvr1NVersion = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneBvr1NVersion") == "true");
	var initdone1NComponent = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NComponent") == "true");
	var initdone1NCall = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NCall") == "true");
	var initdone1NImpexpcplx = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NImpexpcplx") == "true");
	var initdone1NJob = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NJob") == "true");
	var initdone1NOppack = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NOppack") == "true");
	var initdoneVer1NModule = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NModule") == "true");
	var initdone1NPreset = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NPreset") == "true");
	var initdone1NQuery = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NQuery") == "true");
	var initdone1NRelation = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NRelation") == "true");
	var initdone1NTable = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NTable") == "true");
	var initdone1NVector = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NVector") == "true");
	var initdone1NCapability = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdone1NCapability") == "true");
	var initdoneVer1NApp = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NApp") == "true");
	var initdoneVer1NError = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneVer1NError") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneRef1NFile") == "true");
	var initdoneMNLocale = (retrieveSi(srcdoc, "StatAppWznmVerRec", "initdoneMNLocale") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmVerDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NBlock) {
		rhsdoc.getElementById("1NBlock").src = "./PnlWznmVer1NBlock.html?scrJref=" + scrJref1NBlock;
	} else if (!initdoneBvr1NVersion) {
		rhsdoc.getElementById("Bvr1NVersion").src = "./PnlWznmVerBvr1NVersion.html?scrJref=" + scrJrefBvr1NVersion;
	} else if (!initdone1NComponent) {
		rhsdoc.getElementById("1NComponent").src = "./PnlWznmVer1NComponent.html?scrJref=" + scrJref1NComponent;
	} else if (!initdone1NCall) {
		rhsdoc.getElementById("1NCall").src = "./PnlWznmVer1NCall.html?scrJref=" + scrJref1NCall;
	} else if (!initdone1NImpexpcplx) {
		rhsdoc.getElementById("1NImpexpcplx").src = "./PnlWznmVer1NImpexpcplx.html?scrJref=" + scrJref1NImpexpcplx;
	} else if (!initdone1NJob) {
		rhsdoc.getElementById("1NJob").src = "./PnlWznmVer1NJob.html?scrJref=" + scrJref1NJob;
	} else if (!initdone1NOppack) {
		rhsdoc.getElementById("1NOppack").src = "./PnlWznmVer1NOppack.html?scrJref=" + scrJref1NOppack;
	} else if (!initdoneVer1NModule) {
		rhsdoc.getElementById("Ver1NModule").src = "./PnlWznmVerVer1NModule.html?scrJref=" + scrJrefVer1NModule;
	} else if (!initdone1NPreset) {
		rhsdoc.getElementById("1NPreset").src = "./PnlWznmVer1NPreset.html?scrJref=" + scrJref1NPreset;
	} else if (!initdone1NQuery) {
		rhsdoc.getElementById("1NQuery").src = "./PnlWznmVer1NQuery.html?scrJref=" + scrJref1NQuery;
	} else if (!initdone1NRelation) {
		rhsdoc.getElementById("1NRelation").src = "./PnlWznmVer1NRelation.html?scrJref=" + scrJref1NRelation;
	} else if (!initdone1NTable) {
		rhsdoc.getElementById("1NTable").src = "./PnlWznmVer1NTable.html?scrJref=" + scrJref1NTable;
	} else if (!initdone1NVector) {
		rhsdoc.getElementById("1NVector").src = "./PnlWznmVer1NVector.html?scrJref=" + scrJref1NVector;
	} else if (!initdone1NCapability) {
		rhsdoc.getElementById("1NCapability").src = "./PnlWznmVer1NCapability.html?scrJref=" + scrJref1NCapability;
	} else if (!initdoneVer1NApp) {
		rhsdoc.getElementById("Ver1NApp").src = "./PnlWznmVerVer1NApp.html?scrJref=" + scrJrefVer1NApp;
	} else if (!initdoneVer1NError) {
		rhsdoc.getElementById("Ver1NError").src = "./PnlWznmVerVer1NError.html?scrJref=" + scrJrefVer1NError;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlWznmVerRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNLocale) {
		rhsdoc.getElementById("MNLocale").src = "./PnlWznmVerMNLocale.html?scrJref=" + scrJrefMNLocale;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "1NBlock") height1NBlock = height;
		else if (short == "Bvr1NVersion") heightBvr1NVersion = height;
		else if (short == "1NComponent") height1NComponent = height;
		else if (short == "1NCall") height1NCall = height;
		else if (short == "1NImpexpcplx") height1NImpexpcplx = height;
		else if (short == "1NJob") height1NJob = height;
		else if (short == "1NOppack") height1NOppack = height;
		else if (short == "Ver1NModule") heightVer1NModule = height;
		else if (short == "1NPreset") height1NPreset = height;
		else if (short == "1NQuery") height1NQuery = height;
		else if (short == "1NRelation") height1NRelation = height;
		else if (short == "1NTable") height1NTable = height;
		else if (short == "1NVector") height1NVector = height;
		else if (short == "1NCapability") height1NCapability = height;
		else if (short == "Ver1NApp") heightVer1NApp = height;
		else if (short == "Ver1NError") heightVer1NError = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNLocale") heightMNLocale = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmVerRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmVerRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 825);
	doc.getElementById("tdSide").setAttribute("height", "825");
	doc.getElementById("Rec_side").setAttribute("height", "825");
	doc.getElementById("Rec_cont").setAttribute("height", "825");

	doc.getElementById("Rec_side").src = "./PnlWznmVerRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmVerRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "1NBlock") height1NBlock = height;
	else if (pnlshort == "Bvr1NVersion") heightBvr1NVersion = height;
	else if (pnlshort == "1NComponent") height1NComponent = height;
	else if (pnlshort == "1NCall") height1NCall = height;
	else if (pnlshort == "1NImpexpcplx") height1NImpexpcplx = height;
	else if (pnlshort == "1NJob") height1NJob = height;
	else if (pnlshort == "1NOppack") height1NOppack = height;
	else if (pnlshort == "Ver1NModule") heightVer1NModule = height;
	else if (pnlshort == "1NPreset") height1NPreset = height;
	else if (pnlshort == "1NQuery") height1NQuery = height;
	else if (pnlshort == "1NRelation") height1NRelation = height;
	else if (pnlshort == "1NTable") height1NTable = height;
	else if (pnlshort == "1NVector") height1NVector = height;
	else if (pnlshort == "1NCapability") height1NCapability = height;
	else if (pnlshort == "Ver1NApp") heightVer1NApp = height;
	else if (pnlshort == "Ver1NError") heightVer1NError = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNLocale") heightMNLocale = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NBlock+13 + heightBvr1NVersion+13 + height1NComponent+13 + height1NCall+13 + height1NImpexpcplx+13 + height1NJob+13 + height1NOppack+13 + heightVer1NModule+13 + height1NPreset+13 + height1NQuery+13 + height1NRelation+13 + height1NTable+13 + height1NVector+13 + height1NCapability+13 + heightVer1NApp+13 + heightVer1NError+13 + heightRef1NFile+13 + heightMNLocale+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmVerRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmVerRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmVerRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmVerRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmVerRec", "TxtRef"));

};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmVerRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmVerRecData", "ContInfWznmVerRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmVerRecData", "StatAppWznmVerRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmVerRecData", "StatShrWznmVerRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmVerRecData", "TagWznmVerRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmVerRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJref1NBlock) {
				if (getInitdone("1NBlock")) rhsdoc.getElementById("1NBlock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefBvr1NVersion) {
				if (getInitdone("Bvr1NVersion")) rhsdoc.getElementById("Bvr1NVersion").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NComponent) {
				if (getInitdone("1NComponent")) rhsdoc.getElementById("1NComponent").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NCall) {
				if (getInitdone("1NCall")) rhsdoc.getElementById("1NCall").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NImpexpcplx) {
				if (getInitdone("1NImpexpcplx")) rhsdoc.getElementById("1NImpexpcplx").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NJob) {
				if (getInitdone("1NJob")) rhsdoc.getElementById("1NJob").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NOppack) {
				if (getInitdone("1NOppack")) rhsdoc.getElementById("1NOppack").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefVer1NModule) {
				if (getInitdone("Ver1NModule")) rhsdoc.getElementById("Ver1NModule").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NPreset) {
				if (getInitdone("1NPreset")) rhsdoc.getElementById("1NPreset").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NQuery) {
				if (getInitdone("1NQuery")) rhsdoc.getElementById("1NQuery").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NRelation) {
				if (getInitdone("1NRelation")) rhsdoc.getElementById("1NRelation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NTable) {
				if (getInitdone("1NTable")) rhsdoc.getElementById("1NTable").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NVector) {
				if (getInitdone("1NVector")) rhsdoc.getElementById("1NVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NCapability) {
				if (getInitdone("1NCapability")) rhsdoc.getElementById("1NCapability").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefVer1NApp) {
				if (getInitdone("Ver1NApp")) rhsdoc.getElementById("Ver1NApp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefVer1NError) {
				if (getInitdone("Ver1NError")) rhsdoc.getElementById("Ver1NError").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				if (getInitdone("Ref1NFile")) rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLocale) {
				if (getInitdone("MNLocale")) rhsdoc.getElementById("MNLocale").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmVerRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmVerRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmVerRec", "srefIxWznmVExpstate");

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
