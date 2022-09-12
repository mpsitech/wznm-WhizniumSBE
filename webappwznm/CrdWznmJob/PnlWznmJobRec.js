function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefDetail");
	scrJrefAVar = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefAVar");
	scrJrefACmd = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefACmd");
	scrJref1NMethod = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJref1NMethod");
	scrJref1NRtjob = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJref1NRtjob");
	scrJrefJob1NStage = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefJob1NStage");
	scrJref1NSensitivity = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJref1NSensitivity");
	scrJrefHk1NVector = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefHk1NVector");
	scrJrefRef1NBlock = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefRef1NBlock");
	scrJrefMNOppack = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefMNOppack");
	scrJrefMNOp = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefMNOp");
	scrJrefSupMNJob = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefSupMNJob");
	scrJrefSubMNJob = retrieveSi(srcdoc, "StatShrWznmJobRec", "scrJrefSubMNJob");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneAVar", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneACmd", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdone1NMethod", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdone1NRtjob", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneJob1NStage", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdone1NSensitivity", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneHk1NVector", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneRef1NBlock", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneMNOppack", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneMNOp", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneSupMNJob", "false");
	setSi(srcdoc, "StatAppWznmJobRec", "initdoneSubMNJob", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAVar = 30;
	heightACmd = 30;
	height1NMethod = 30;
	height1NRtjob = 30;
	heightJob1NStage = 30;
	height1NSensitivity = 30;
	heightHk1NVector = 30;
	heightRef1NBlock = 30;
	heightMNOppack = 30;
	heightMNOp = 30;
	heightSupMNJob = 30;
	heightSubMNJob = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWznmJobRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWznmJobRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneDetail") == "true");
	var initdoneAVar = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneAVar") == "true");
	var initdoneACmd = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneACmd") == "true");
	var initdone1NMethod = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdone1NMethod") == "true");
	var initdone1NRtjob = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdone1NRtjob") == "true");
	var initdoneJob1NStage = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneJob1NStage") == "true");
	var initdone1NSensitivity = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdone1NSensitivity") == "true");
	var initdoneHk1NVector = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneHk1NVector") == "true");
	var initdoneRef1NBlock = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneRef1NBlock") == "true");
	var initdoneMNOppack = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneMNOppack") == "true");
	var initdoneMNOp = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneMNOp") == "true");
	var initdoneSupMNJob = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneSupMNJob") == "true");
	var initdoneSubMNJob = (retrieveSi(srcdoc, "StatAppWznmJobRec", "initdoneSubMNJob") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWznmJobDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAVar) {
		lhsdoc.getElementById("AVar").src = "./PnlWznmJobAVar.html?scrJref=" + scrJrefAVar;
	} else if (!initdoneACmd) {
		lhsdoc.getElementById("ACmd").src = "./PnlWznmJobACmd.html?scrJref=" + scrJrefACmd;
	} else if (!initdone1NMethod) {
		rhsdoc.getElementById("1NMethod").src = "./PnlWznmJob1NMethod.html?scrJref=" + scrJref1NMethod;
	} else if (!initdone1NRtjob) {
		rhsdoc.getElementById("1NRtjob").src = "./PnlWznmJob1NRtjob.html?scrJref=" + scrJref1NRtjob;
	} else if (!initdoneJob1NStage) {
		rhsdoc.getElementById("Job1NStage").src = "./PnlWznmJobJob1NStage.html?scrJref=" + scrJrefJob1NStage;
	} else if (!initdone1NSensitivity) {
		rhsdoc.getElementById("1NSensitivity").src = "./PnlWznmJob1NSensitivity.html?scrJref=" + scrJref1NSensitivity;
	} else if (!initdoneHk1NVector) {
		rhsdoc.getElementById("Hk1NVector").src = "./PnlWznmJobHk1NVector.html?scrJref=" + scrJrefHk1NVector;
	} else if (!initdoneRef1NBlock) {
		rhsdoc.getElementById("Ref1NBlock").src = "./PnlWznmJobRef1NBlock.html?scrJref=" + scrJrefRef1NBlock;
	} else if (!initdoneMNOppack) {
		rhsdoc.getElementById("MNOppack").src = "./PnlWznmJobMNOppack.html?scrJref=" + scrJrefMNOppack;
	} else if (!initdoneMNOp) {
		rhsdoc.getElementById("MNOp").src = "./PnlWznmJobMNOp.html?scrJref=" + scrJrefMNOp;
	} else if (!initdoneSupMNJob) {
		rhsdoc.getElementById("SupMNJob").src = "./PnlWznmJobSupMNJob.html?scrJref=" + scrJrefSupMNJob;
	} else if (!initdoneSubMNJob) {
		rhsdoc.getElementById("SubMNJob").src = "./PnlWznmJobSubMNJob.html?scrJref=" + scrJrefSubMNJob;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AVar") || (short == "ACmd")) lhsrhsdoc = lhsdoc;
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
		else if (short == "AVar") heightAVar = height;
		else if (short == "ACmd") heightACmd = height;
		else if (short == "1NMethod") height1NMethod = height;
		else if (short == "1NRtjob") height1NRtjob = height;
		else if (short == "Job1NStage") heightJob1NStage = height;
		else if (short == "1NSensitivity") height1NSensitivity = height;
		else if (short == "Hk1NVector") heightHk1NVector = height;
		else if (short == "Ref1NBlock") heightRef1NBlock = height;
		else if (short == "MNOppack") heightMNOppack = height;
		else if (short == "MNOp") heightMNOp = height;
		else if (short == "SupMNJob") heightSupMNJob = height;
		else if (short == "SubMNJob") heightSubMNJob = height;
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

	doc.getElementById("Rec_side").src = "./PnlWznmJobRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmJobRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 481);
	doc.getElementById("tdSide").setAttribute("height", "481");
	doc.getElementById("Rec_side").setAttribute("height", "481");
	doc.getElementById("Rec_cont").setAttribute("height", "481");

	doc.getElementById("Rec_side").src = "./PnlWznmJobRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWznmJobRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AVar") || (pnlshort == "ACmd")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AVar") heightAVar = height;
	else if (pnlshort == "ACmd") heightACmd = height;
	else if (pnlshort == "1NMethod") height1NMethod = height;
	else if (pnlshort == "1NRtjob") height1NRtjob = height;
	else if (pnlshort == "Job1NStage") heightJob1NStage = height;
	else if (pnlshort == "1NSensitivity") height1NSensitivity = height;
	else if (pnlshort == "Hk1NVector") heightHk1NVector = height;
	else if (pnlshort == "Ref1NBlock") heightRef1NBlock = height;
	else if (pnlshort == "MNOppack") heightMNOppack = height;
	else if (pnlshort == "MNOp") heightMNOp = height;
	else if (pnlshort == "SupMNJob") heightSupMNJob = height;
	else if (pnlshort == "SubMNJob") heightSubMNJob = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAVar+13 + heightACmd+13 + 5;
	heightRhs = height1NMethod+13 + height1NRtjob+13 + heightJob1NStage+13 + height1NSensitivity+13 + heightHk1NVector+13 + heightRef1NBlock+13 + heightMNOppack+13 + heightMNOp+13 + heightSupMNJob+13 + heightSubMNJob+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmJobRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWznmJobRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

	if (srefIxWznmVExpstate == "mind") {
		minimize();
	} else if (srefIxWznmVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWznmJobRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmJobRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlsubmnjobAvail = (retrieveSi(srcdoc, "StatShrWznmJobRec", "pnlsubmnjobAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWznmJobRec", "TxtRef"));

	if (setPnlAvail("SubMNJob", pnlsubmnjobAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWznmJobRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWznmJobRecData", "ContInfWznmJobRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWznmJobRecData", "StatAppWznmJobRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWznmJobRecData", "StatShrWznmJobRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWznmJobRecData", "TagWznmJobRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWznmVExpstate, newSrefIxWznmVExpstate;

	_scrJref = retrieveValue(dom, "//wznm:*/wznm:scrJref");
	srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWznmJobRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

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
			} else if (_scrJref == scrJrefAVar) {
				if (getInitdone("AVar")) lhsdoc.getElementById("AVar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefACmd) {
				if (getInitdone("ACmd")) lhsdoc.getElementById("ACmd").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NMethod) {
				if (getInitdone("1NMethod")) rhsdoc.getElementById("1NMethod").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NRtjob) {
				if (getInitdone("1NRtjob")) rhsdoc.getElementById("1NRtjob").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefJob1NStage) {
				if (getInitdone("Job1NStage")) rhsdoc.getElementById("Job1NStage").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NSensitivity) {
				if (getInitdone("1NSensitivity")) rhsdoc.getElementById("1NSensitivity").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVector) {
				if (getInitdone("Hk1NVector")) rhsdoc.getElementById("Hk1NVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NBlock) {
				if (getInitdone("Ref1NBlock")) rhsdoc.getElementById("Ref1NBlock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNOppack) {
				if (getInitdone("MNOppack")) rhsdoc.getElementById("MNOppack").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNOp) {
				if (getInitdone("MNOp")) rhsdoc.getElementById("MNOp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSupMNJob) {
				if (getInitdone("SupMNJob")) rhsdoc.getElementById("SupMNJob").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSubMNJob) {
				if (getInitdone("SubMNJob")) rhsdoc.getElementById("SubMNJob").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWznmJobRecData") {
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

			} else if (blk.nodeName == "DpchEngWznmJobRecData") {
				srefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWznmVExpstate = retrieveSi(srcdoc, "StatShrWznmJobRec", "srefIxWznmVExpstate");

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
