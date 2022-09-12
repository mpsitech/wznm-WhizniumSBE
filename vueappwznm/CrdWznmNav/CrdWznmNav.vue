<template>
	<div v-if="initdonePnls">
		<div class="d-flex pa-2 align-center">
			<img src="../../assets/logo.png" height="56" alt="logo" class="mr-1">
			<div>
				<div class="title font-weight-bold text-uppercase primary--text mx-2">{{CptTitle}}</div>
				<div class="caption grey--text mx-2">{{CptVersion}}</div>
			</div>
		</div>

		<v-divider/>

		<v-list>
			<v-list-item-group v-model="MenApp">
				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppAbtClick')"
					value="MitAppAbt"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppAbt}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					v-if="statshr.MitAppLoiAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppLoiClick')"
					value="MitAppLoi"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppLoi}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group>
				<v-list-item
					v-if="statshr.MitSesSpsAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesSpsClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesSps}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesTrmClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesTrm}}</v-list-item-title>
					</v-list-item-content>
					<v-tooltip right>
						<template v-slot:activator="{on,attrs}">
							<v-list-item-icon>
								<v-icon v-bind="attrs" v-on="on">mdi-information-outline</v-icon>
							</v-list-item-icon>
						</template>
						{{continf.MtxSesSes1 + " " + continf.MtxSesSes2 + " " + continf.MtxSesSes3}}
					</v-tooltip>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group v-if="statshr.pnlpreAvail">
				<v-list-item
					v-for="(short, j) in mitsPre"
					:key="j"
					active-class="red--text"
					class="red--text"
				>
					<v-list-item-content>
						<v-list-item-subtitle class="red--text text--lighten-3 overline">{{pnlpre.tag['Cpt' + short]}}</v-list-item-subtitle>
						<v-list-item-title>{{pnlpre.continf['Txt' + short]}}</v-list-item-title>
					</v-list-item-content>
					<v-list-item-icon>
						<v-icon
							color="red"
							v-on:click="handleButClick_other('Pre', statshr.scrJrefPre, 'But' + short + 'RemoveClick')"
						>
							mdi-close-circle-outline
						</v-icon>
					</v-list-item-icon>
				</v-list-item>
			</v-list-item-group>

			<v-divider v-if="statshr.pnlpreAvail"/>

			<v-list-item-group v-for="({sref, mits}, i) in MbarContent" :key="i" v-model="MbarContent[i].mit">
				<v-list-item small disabled dense class="grey lighten-5">
					<v-list-item-content :style="{'text-align':'right'}">
						<v-list-item-title class="grey--text text--darken-4 overline">{{MenContentHdg(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>

				<v-list-item
					v-for="(sref, j) in mitsContent(mits)"
					:key="j"
					active-class="grey lighten-5"
					class="grey lighten-5"
					v-on:click="handleMitContentClick(sref + 'Click')"
					:value="sref"
					:disabled="!MitContentActive(sref)"
				>
					<v-list-item-content>
						<v-list-item-title>{{MitContent(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>
			</v-list-item-group>

			<v-list-item small disabled dense>
				<v-list-item-content :style="{'text-align':'right'}">
					<v-list-item-title class="overline">{{pnlheadbar.tag.MenCrd}}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>

			<v-divider/>

			<v-list-item-group mandatory>
				<v-list-group v-for="({pnlsref, mits}, i) in MenCrd" :key="i">
					<template v-slot:activator>
						<v-list-item-content>
							<v-list-item-title>{{MenCrdHdg(pnlsref)}}</v-list-item-title>
						</v-list-item-content>
					</template>

					<v-list-item
						v-for="(sref, j) in mitsCrd(mits)"
						:key="j"
						active-class="primary--text"
						v-on:click="handleMitCrdopenClick(sref + 'Click')"
						:value="sref"
						:disabled="!MitCrdActive(sref)"
					>
						<v-tooltip right>
							<template v-slot:activator="{on,attrs}">
								<v-list-item-content v-bind="attrs" v-on="on">
									<v-list-item-title>{{MitCrd(sref)}}</v-list-item-title>
								</v-list-item-content>
							</template><span v-html="LstHist(pnlsref, sref.substring(3 + 3))"/>
						</v-tooltip>
					</v-list-item>
				</v-list-group>

				<v-divider/>
			</v-list-item-group>
		</v-list>
	</div>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmNav',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("CrdWznmNav.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleMitClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitCrdopenClick: function(ctlsref) {
				if (this.content.sref.substring(3 + 4) == ctlsref.substring(3 + 3, 3 + 3 + 3)) return;

				const dpchapp = {
					"DpchAppWznmNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppCrdopenReply"});
			},

			handleButClick_other: function(sref, scrJref, ctlsref) {
				var dpchapp = {};
				dpchapp["DpchAppWznmNav" + sref + "Do"] = {
					"scrJref": scrJref,
					"srefIxVDo": ctlsref
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitContentClick: function(ctlsref) {
				var dpchapp = {};
				dpchapp["DpchApp" + this.content.sref.substring(3) + "Do"] = {
					"scrJref": this.content.scrJref,
					"srefIxVDo": ctlsref
				};

				this.$emit("request", {scrJref: this.content.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"}); // reply ends up in content card
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWznmNav) this.continf = dpcheng.ContInfWznmNav;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmNav) this.statapp = dpcheng.StatAppWznmNav;
				if (dpcheng.StatShrWznmNav) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmNav.scrJrefDlgloaini != "") || (dpcheng.StatShrWznmNav.scrJrefDlgmnglic != ""));
						dlgclose = ((this.statshr.scrJrefDlgloaini != "") || (this.statshr.scrJrefDlgmnglic != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmNav.scrJrefDlgloaini != "") {
								srefDlg = "DlgWznmNavLoaini";
								scrJrefDlg = dpcheng.StatShrWznmNav.scrJrefDlgloaini;
							} else if (dpcheng.StatShrWznmNav.scrJrefDlgmnglic != "") {
								srefDlg = "DlgWznmNavMnglic";
								scrJrefDlg = dpcheng.StatShrWznmNav.scrJrefDlgmnglic;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmNav;
				}
				if (dpcheng.TagWznmNav) {
					Wznm.unescapeBlock(dpcheng.TagWznmNav);
					this.tag = dpcheng.TagWznmNav;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			/*
			*/
			mergeDpchEngData_pnlheadbar: function(dpcheng) {
				if (dpcheng.StatShrWznmNavHeadbar) this.pnlheadbar.statshr = dpcheng.StatShrWznmNavHeadbar;
				if (dpcheng.StgInfWznmNavHeadbar) this.pnlheadbar.stginf = dpcheng.StgInfWznmNavHeadbar;
				if (dpcheng.TagWznmNavHeadbar) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavHeadbar);
					this.pnlheadbar.tag = dpcheng.TagWznmNavHeadbar;
				}
			},

			mergeDpchEngData_pnlpre: function(dpcheng) {
				if (dpcheng.ContInfWznmNavPre) this.pnlpre.continf = dpcheng.ContInfWznmNavPre;
				if (dpcheng.StatShrWznmNavPre) this.pnlpre.statshr = dpcheng.StatShrWznmNavPre;
				if (dpcheng.TagWznmNavPre) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavPre);
					this.pnlpre.tag = dpcheng.TagWznmNavPre;
				}
			},

			mergeDpchEngData_pnladmin: function(dpcheng) {
				if (dpcheng.ContIacWznmNavAdmin) this.pnladmin.contiac = dpcheng.ContIacWznmNavAdmin;
				if (dpcheng.FeedFLstFil) this.pnladmin.feedFLstFil = dpcheng.FeedFLstFil;
				if (dpcheng.FeedFLstPrs) this.pnladmin.feedFLstPrs = dpcheng.FeedFLstPrs;
				if (dpcheng.FeedFLstUsg) this.pnladmin.feedFLstUsg = dpcheng.FeedFLstUsg;
				if (dpcheng.FeedFLstUsr) this.pnladmin.feedFLstUsr = dpcheng.FeedFLstUsr;
				if (dpcheng.StatAppWznmNavAdmin) this.pnladmin.statapp = dpcheng.StatAppWznmNavAdmin;
				if (dpcheng.StatShrWznmNavAdmin) this.pnladmin.statshr = dpcheng.StatShrWznmNavAdmin;
				if (dpcheng.TagWznmNavAdmin) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavAdmin);
					this.pnladmin.tag = dpcheng.TagWznmNavAdmin;
				}
			},

			mergeDpchEngData_pnlglobal: function(dpcheng) {
				if (dpcheng.ContIacWznmNavGlobal) this.pnlglobal.contiac = dpcheng.ContIacWznmNavGlobal;
				if (dpcheng.FeedFLstCtp) this.pnlglobal.feedFLstCtp = dpcheng.FeedFLstCtp;
				if (dpcheng.FeedFLstLib) this.pnlglobal.feedFLstLib = dpcheng.FeedFLstLib;
				if (dpcheng.FeedFLstLoc) this.pnlglobal.feedFLstLoc = dpcheng.FeedFLstLoc;
				if (dpcheng.FeedFLstMch) this.pnlglobal.feedFLstMch = dpcheng.FeedFLstMch;
				if (dpcheng.FeedFLstTag) this.pnlglobal.feedFLstTag = dpcheng.FeedFLstTag;
				if (dpcheng.StatAppWznmNavGlobal) this.pnlglobal.statapp = dpcheng.StatAppWznmNavGlobal;
				if (dpcheng.StatShrWznmNavGlobal) this.pnlglobal.statshr = dpcheng.StatShrWznmNavGlobal;
				if (dpcheng.TagWznmNavGlobal) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavGlobal);
					this.pnlglobal.tag = dpcheng.TagWznmNavGlobal;
				}
			},

			mergeDpchEngData_pnlproject: function(dpcheng) {
				if (dpcheng.ContIacWznmNavProject) this.pnlproject.contiac = dpcheng.ContIacWznmNavProject;
				if (dpcheng.FeedFLstCap) this.pnlproject.feedFLstCap = dpcheng.FeedFLstCap;
				if (dpcheng.FeedFLstErr) this.pnlproject.feedFLstErr = dpcheng.FeedFLstErr;
				if (dpcheng.FeedFLstPrj) this.pnlproject.feedFLstPrj = dpcheng.FeedFLstPrj;
				if (dpcheng.FeedFLstVer) this.pnlproject.feedFLstVer = dpcheng.FeedFLstVer;
				if (dpcheng.StatAppWznmNavProject) this.pnlproject.statapp = dpcheng.StatAppWznmNavProject;
				if (dpcheng.StatShrWznmNavProject) this.pnlproject.statshr = dpcheng.StatShrWznmNavProject;
				if (dpcheng.TagWznmNavProject) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavProject);
					this.pnlproject.tag = dpcheng.TagWznmNavProject;
				}
			},

			mergeDpchEngData_pnldbstr: function(dpcheng) {
				if (dpcheng.ContIacWznmNavDbstr) this.pnldbstr.contiac = dpcheng.ContIacWznmNavDbstr;
				if (dpcheng.FeedFLstChk) this.pnldbstr.feedFLstChk = dpcheng.FeedFLstChk;
				if (dpcheng.FeedFLstIel) this.pnldbstr.feedFLstIel = dpcheng.FeedFLstIel;
				if (dpcheng.FeedFLstIex) this.pnldbstr.feedFLstIex = dpcheng.FeedFLstIex;
				if (dpcheng.FeedFLstIme) this.pnldbstr.feedFLstIme = dpcheng.FeedFLstIme;
				if (dpcheng.FeedFLstRel) this.pnldbstr.feedFLstRel = dpcheng.FeedFLstRel;
				if (dpcheng.FeedFLstSbs) this.pnldbstr.feedFLstSbs = dpcheng.FeedFLstSbs;
				if (dpcheng.FeedFLstStb) this.pnldbstr.feedFLstStb = dpcheng.FeedFLstStb;
				if (dpcheng.FeedFLstTbl) this.pnldbstr.feedFLstTbl = dpcheng.FeedFLstTbl;
				if (dpcheng.FeedFLstTco) this.pnldbstr.feedFLstTco = dpcheng.FeedFLstTco;
				if (dpcheng.FeedFLstVec) this.pnldbstr.feedFLstVec = dpcheng.FeedFLstVec;
				if (dpcheng.FeedFLstVit) this.pnldbstr.feedFLstVit = dpcheng.FeedFLstVit;
				if (dpcheng.StatAppWznmNavDbstr) this.pnldbstr.statapp = dpcheng.StatAppWznmNavDbstr;
				if (dpcheng.StatShrWznmNavDbstr) this.pnldbstr.statshr = dpcheng.StatShrWznmNavDbstr;
				if (dpcheng.TagWznmNavDbstr) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavDbstr);
					this.pnldbstr.tag = dpcheng.TagWznmNavDbstr;
				}
			},

			mergeDpchEngData_pnluix: function(dpcheng) {
				if (dpcheng.ContIacWznmNavUix) this.pnluix.contiac = dpcheng.ContIacWznmNavUix;
				if (dpcheng.FeedFLstCar) this.pnluix.feedFLstCar = dpcheng.FeedFLstCar;
				if (dpcheng.FeedFLstCon) this.pnluix.feedFLstCon = dpcheng.FeedFLstCon;
				if (dpcheng.FeedFLstDlg) this.pnluix.feedFLstDlg = dpcheng.FeedFLstDlg;
				if (dpcheng.FeedFLstMdl) this.pnluix.feedFLstMdl = dpcheng.FeedFLstMdl;
				if (dpcheng.FeedFLstPnl) this.pnluix.feedFLstPnl = dpcheng.FeedFLstPnl;
				if (dpcheng.FeedFLstPst) this.pnluix.feedFLstPst = dpcheng.FeedFLstPst;
				if (dpcheng.FeedFLstQco) this.pnluix.feedFLstQco = dpcheng.FeedFLstQco;
				if (dpcheng.FeedFLstQmd) this.pnluix.feedFLstQmd = dpcheng.FeedFLstQmd;
				if (dpcheng.FeedFLstQry) this.pnluix.feedFLstQry = dpcheng.FeedFLstQry;
				if (dpcheng.StatAppWznmNavUix) this.pnluix.statapp = dpcheng.StatAppWznmNavUix;
				if (dpcheng.StatShrWznmNavUix) this.pnluix.statshr = dpcheng.StatShrWznmNavUix;
				if (dpcheng.TagWznmNavUix) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavUix);
					this.pnluix.tag = dpcheng.TagWznmNavUix;
				}
			},

			mergeDpchEngData_pnlcomp: function(dpcheng) {
				if (dpcheng.ContIacWznmNavComp) this.pnlcomp.contiac = dpcheng.ContIacWznmNavComp;
				if (dpcheng.FeedFLstOpk) this.pnlcomp.feedFLstOpk = dpcheng.FeedFLstOpk;
				if (dpcheng.FeedFLstOpx) this.pnlcomp.feedFLstOpx = dpcheng.FeedFLstOpx;
				if (dpcheng.StatAppWznmNavComp) this.pnlcomp.statapp = dpcheng.StatAppWznmNavComp;
				if (dpcheng.StatShrWznmNavComp) this.pnlcomp.statshr = dpcheng.StatShrWznmNavComp;
				if (dpcheng.TagWznmNavComp) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavComp);
					this.pnlcomp.tag = dpcheng.TagWznmNavComp;
				}
			},

			mergeDpchEngData_pnljob: function(dpcheng) {
				if (dpcheng.ContIacWznmNavJob) this.pnljob.contiac = dpcheng.ContIacWznmNavJob;
				if (dpcheng.FeedFLstBlk) this.pnljob.feedFLstBlk = dpcheng.FeedFLstBlk;
				if (dpcheng.FeedFLstCal) this.pnljob.feedFLstCal = dpcheng.FeedFLstCal;
				if (dpcheng.FeedFLstJob) this.pnljob.feedFLstJob = dpcheng.FeedFLstJob;
				if (dpcheng.FeedFLstMtd) this.pnljob.feedFLstMtd = dpcheng.FeedFLstMtd;
				if (dpcheng.FeedFLstSge) this.pnljob.feedFLstSge = dpcheng.FeedFLstSge;
				if (dpcheng.StatAppWznmNavJob) this.pnljob.statapp = dpcheng.StatAppWznmNavJob;
				if (dpcheng.StatShrWznmNavJob) this.pnljob.statshr = dpcheng.StatShrWznmNavJob;
				if (dpcheng.TagWznmNavJob) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavJob);
					this.pnljob.tag = dpcheng.TagWznmNavJob;
				}
			},

			mergeDpchEngData_pnldeploy: function(dpcheng) {
				if (dpcheng.ContIacWznmNavDeploy) this.pnldeploy.contiac = dpcheng.ContIacWznmNavDeploy;
				if (dpcheng.FeedFLstCmp) this.pnldeploy.feedFLstCmp = dpcheng.FeedFLstCmp;
				if (dpcheng.FeedFLstRls) this.pnldeploy.feedFLstRls = dpcheng.FeedFLstRls;
				if (dpcheng.StatAppWznmNavDeploy) this.pnldeploy.statapp = dpcheng.StatAppWznmNavDeploy;
				if (dpcheng.StatShrWznmNavDeploy) this.pnldeploy.statshr = dpcheng.StatShrWznmNavDeploy;
				if (dpcheng.TagWznmNavDeploy) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavDeploy);
					this.pnldeploy.tag = dpcheng.TagWznmNavDeploy;
				}
			},

			mergeDpchEngData_pnlappdev: function(dpcheng) {
				if (dpcheng.ContIacWznmNavAppdev) this.pnlappdev.contiac = dpcheng.ContIacWznmNavAppdev;
				if (dpcheng.FeedFLstApp) this.pnlappdev.feedFLstApp = dpcheng.FeedFLstApp;
				if (dpcheng.FeedFLstEvt) this.pnlappdev.feedFLstEvt = dpcheng.FeedFLstEvt;
				if (dpcheng.FeedFLstRtj) this.pnlappdev.feedFLstRtj = dpcheng.FeedFLstRtj;
				if (dpcheng.FeedFLstSeq) this.pnlappdev.feedFLstSeq = dpcheng.FeedFLstSeq;
				if (dpcheng.FeedFLstSte) this.pnlappdev.feedFLstSte = dpcheng.FeedFLstSte;
				if (dpcheng.StatAppWznmNavAppdev) this.pnlappdev.statapp = dpcheng.StatAppWznmNavAppdev;
				if (dpcheng.StatShrWznmNavAppdev) this.pnlappdev.statshr = dpcheng.StatShrWznmNavAppdev;
				if (dpcheng.TagWznmNavAppdev) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavAppdev);
					this.pnlappdev.tag = dpcheng.TagWznmNavAppdev;
				}
			},

			mergeDpchEngData_pnlauxfct: function(dpcheng) {
				if (dpcheng.StatAppWznmNavAuxfct) this.pnlauxfct.statapp = dpcheng.StatAppWznmNavAuxfct;
				if (dpcheng.StatShrWznmNavAuxfct) this.pnlauxfct.statshr = dpcheng.StatShrWznmNavAuxfct;
				if (dpcheng.TagWznmNavAuxfct) {
					Wznm.unescapeBlock(dpcheng.TagWznmNavAuxfct);
					this.pnlauxfct.tag = dpcheng.TagWznmNavAuxfct;
				}
			},

			/*
			*/

			mergeDpchEngData_content: function(dpcheng) {
				if (dpcheng["StatShr" + this.content.sref.substring(3)]) this.content.statshr = dpcheng["StatShr" + this.content.sref.substring(3)];
				if (dpcheng["Tag" + this.content.sref.substring(3)]) {
					Wznm.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3)]);
					this.content.tag = dpcheng["Tag" + this.content.sref.substring(3)];
				}

				this.$forceUpdate();
			},

			mergeDpchEngData_contentpnlheadbar: function(dpcheng) {
				if (dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]) {
					Wznm.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]);
					this.content.pnlheadbar.tag = dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"];
				}

				this.MbarContent = this["Mbar" + this.content.sref.substring(3 + 4)]
			},

			handleCrdopen: function(obj) {
				//console.log(obj.srefCrd);
				this.MenNav = "MitCrd" + obj.srefCrd.substring(3 + 4);

				this.content.sref = obj.srefCrd;
				this.content.scrJref = obj.scrJrefCrd;

				this.content.statshr = {};
				this.content.tag = {};

				this.content.initdone = false;
				this.content.pnlheadbar.initdone = false;

				this.initOther(this.content.scrJref);

				// obj content {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false}
			},

			handleAlrdlgclose: function() {
				this.MenApp = 0;
				for (var men in this.MbarContent) this.MbarContent[men].mit = 0
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppCrdopenReply") this.handleDpchAppCrdopenReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDoReply") this.handleDpchAppDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleUpdate: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmNavData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdonePnls) {
					if (obj.dpcheng.scrJref == this.statshr.scrJrefAdmin) this.mergeDpchEngData_pnladmin(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefMon) this.mergeDpchEngData_pnlmon(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.mergeDpchEngData_pnlpre(obj.dpcheng);

					if (this.content.initdone) if (obj.dpcheng.scrJref == this.content.scrJref) this.mergeDpchEngData_content(obj.dpcheng);
				}
			},

			initOther: function(scrJref) {
				const dpchapp = {
					"DpchAppWznmInit": {
						"scrJref": scrJref
					}
				};

				this.$emit("request", {scrJref: scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
			},

			handleDpchAppInitReply: function(dpcheng) {
				if (dpcheng.scrJref == this.scrJref) {
					this.mergeDpchEngData(dpcheng);
					this.initdone = true;
				}

				if (this.initdone) {
					/*
					*/
					if (dpcheng.scrJref == this.statshr.scrJrefHeadbar) {
						this.mergeDpchEngData_pnlheadbar(dpcheng);
						this.statapp.initdoneHeadbar = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefPre) {
						this.mergeDpchEngData_pnlpre(dpcheng);
						this.statapp.initdonePre = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAdmin) {
						this.mergeDpchEngData_pnladmin(dpcheng);
						this.statapp.initdoneAdmin = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefGlobal) {
						this.mergeDpchEngData_pnlglobal(dpcheng);
						this.statapp.initdoneGlobal = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefProject) {
						this.mergeDpchEngData_pnlproject(dpcheng);
						this.statapp.initdoneProject = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefDbstr) {
						this.mergeDpchEngData_pnldbstr(dpcheng);
						this.statapp.initdoneDbstr = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefUix) {
						this.mergeDpchEngData_pnluix(dpcheng);
						this.statapp.initdoneUix = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefComp) {
						this.mergeDpchEngData_pnlcomp(dpcheng);
						this.statapp.initdoneComp = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefJob) {
						this.mergeDpchEngData_pnljob(dpcheng);
						this.statapp.initdoneJob = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefDeploy) {
						this.mergeDpchEngData_pnldeploy(dpcheng);
						this.statapp.initdoneDeploy = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAppdev) {
						this.mergeDpchEngData_pnlappdev(dpcheng);
						this.statapp.initdoneAppdev = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAuxfct) {
						this.mergeDpchEngData_pnlauxfct(dpcheng);
						this.statapp.initdoneAuxfct = true;
					} else if (dpcheng.scrJref == this.content.scrJref) {
						this.mergeDpchEngData_content(dpcheng);
						this.content.initdone = true;
					}

					if (!this.statapp.initdoneHeadbar) this.initOther(this.statshr.scrJrefHeadbar);
					else if (!this.statapp.initdonePre) this.initOther(this.statshr.scrJrefPre);
					else if (!this.statapp.initdoneAdmin) this.initOther(this.statshr.scrJrefAdmin);
					else if (!this.statapp.initdoneGlobal) this.initOther(this.statshr.scrJrefGlobal);
					else if (!this.statapp.initdoneProject) this.initOther(this.statshr.scrJrefProject);
					else if (!this.statapp.initdoneDbstr) this.initOther(this.statshr.scrJrefDbstr);
					else if (!this.statapp.initdoneUix) this.initOther(this.statshr.scrJrefUix);
					else if (!this.statapp.initdoneComp) this.initOther(this.statshr.scrJrefComp);
					else if (!this.statapp.initdoneJob) this.initOther(this.statshr.scrJrefJob);
					else if (!this.statapp.initdoneDeploy) this.initOther(this.statshr.scrJrefDeploy);
					else if (!this.statapp.initdoneAppdev) this.initOther(this.statshr.scrJrefAppdev);
					else if (!this.statapp.initdoneAuxfct) this.initOther(this.statshr.scrJrefAuxfct);
					/*
					*/
					else this.initdonePnls = true;

					if (this.content.initdone) {
						if (dpcheng.scrJref == this.content.statshr.scrJrefHeadbar) {
							this.mergeDpchEngData_contentpnlheadbar(dpcheng);
							this.content.pnlheadbar.initdone = true;
						}
		
						if (!this.content.pnlheadbar.initdone) this.initOther(this.content.statshr.scrJrefHeadbar);
					}
				}
			},

			handleDpchAppDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmNavData") this.mergeDpchEngData(dpcheng);
				else if (srefIxWznmVDpch == "DpchEngWznmNavPreData") this.mergeDpchEngData_pnlpre(dpcheng);
			},

			handleDpchAppCrdopenReply: function(dpcheng) {
				if (dpcheng.accepted) {
					//console.log("CrdWznmNav.handleDpchAppCrdopenReply() accepted");

					this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});

				} else {
					//console.log("CrdWznmNav.handleDpchAppCrdopenReply() denied");
				}
			},

			// (static) CrdNav.MenApp: tag

			// (static) CrdNav.MenSes: tag, continf (pop-up)

			// (dynamic) CrdNav.MenCrd: pnl*.tag (module), crd.tag (mit). pnl*.continf (history)
			MenCrdHdg: function(pnlsref) {
				if (this[pnlsref] == null) return pnlsref;
				return this[pnlsref].tag.Cpt;
			},

			mitsCrd: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.statshr[ctlsref + "Avail"] != null) if (this.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}
					
				return mits
			},

			MitCrd: function(ctlsref) {
				if (this.tag[ctlsref] == null) return ctlsref;
				return this.tag[ctlsref]
			},

			MitCrdActive: function(ctlsref) {
				if (this.statshr[ctlsref + "Active"] == null) return true;
				return this.statshr[ctlsref + "Active"]
			},

			// (dynamic) PnlNavPre: tag, continf

			// (dynamic) content.Mbar: pnlheadbar.tag (men), crd.tag (mit)
			MenContentHdg: function(ctlsref) {
				if (this.content.pnlheadbar.tag == null) return ctlsref;
				if (this.content.pnlheadbar.tag[ctlsref] == null) return ctlsref;
				return this.content.pnlheadbar.tag[ctlsref];
			},

			mitsContent: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.content.statshr[ctlsref + "Avail"] != null) if (this.content.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}

				return mits
			},

			MitContent: function(ctlsref) {
				if (this.content.tag == null) return ctlsref;
				if (this.content.tag[ctlsref] == null) return ctlsref;
				return this.content.tag[ctlsref];
			},

			MitContentActive: function(ctlsref) {
				if (this.content.statshr == null) return true;
				if (this.content.statshr[ctlsref + "Active"] == null) return true;
				return this.content.statshr[ctlsref + "Active"]
			},

			LstHist: function(pnlsref, short) {
				var retval = "";
				const feed = this[pnlsref]["feedFLst" + short];

				if (feed != null)
					for (var i = 0; i < feed.length; i++) {
						var fi = feed[i];
						retval += "<p class='mb-0'>" + fi.tit1 + "</p>";
					}

				return retval;
			}
		},

		computed: {
			CptTitle: function() {
				return Wznm.title;
			},

			CptVersion: function() {
				return("v" + Wznm.version);
			},

			MenApp: {
				get() {
					return this.MenApp_last;
				},
				set(sel) {
					if (sel == null) this.MenApp_last = 0;
					else this.MenApp_last = sel;
					
					return sel;
				}
			},

			mitsPre: function() {
				var mits = [];

				for (const short of this.MenPre) if (this.pnlpre.statshr["Txt" + short + "Avail"]) mits.push(short);

				return mits
			}
		},

		data: () => ({
			initdone: false,
			initdonePnls: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/

			MenApp_last: 0,

			/*
			*/
			MenPre: ["App", "Ver"],
			/*
			*/

			/*
			*/
			MenCrd: [
				{
					pnlsref: "pnladmin",
					mits: ["MitCrdUsg", "MitCrdUsr", "MitCrdPrs", "MitCrdFil"]
				},
				{
					pnlsref: "pnlglobal",
					mits: ["MitCrdLoc", "MitCrdTag", "MitCrdCtp", "MitCrdMch", "MitCrdLib"]
				},
				{
					pnlsref: "pnlproject",
					mits: ["MitCrdPrj", "MitCrdVer", "MitCrdCap", "MitCrdErr"]
				},
				{
					pnlsref: "pnldbstr",
					mits: ["MitCrdTbl", "MitCrdTco", "MitCrdSbs", "MitCrdRel", "MitCrdVec", "MitCrdVit", "MitCrdChk", "MitCrdStb", "MitCrdIex", "MitCrdIme"]
				},
				{
					pnlsref: "pnluix",
					mits: ["MitCrdPst", "MitCrdMdl", "MitCrdCar", "MitCrdDlg", "MitCrdPnl", "MitCrdQry", "MitCrdQco", "MitCrdQmd", "MitCrdCon"]
				},
				{
					pnlsref: "pnlcomp",
					mits: ["MitCrdOpk", "MitCrdOpx"]
				},
				{
					pnlsref: "pnljob",
					mits: ["MitCrdJob", "MitCrdSge", "MitCrdMtd", "MitCrdBlk", "MitCrdCal"]
				},
				{
					pnlsref: "pnldeploy",
					mits: ["MitCrdCmp", "MitCrdRls"]
				},
				{
					pnlsref: "pnlappdev",
					mits: ["MitCrdApp", "MitCrdRtj", "MitCrdEvt", "MitCrdSeq", "MitCrdSte"]
				},
				{
					pnlsref: "pnlauxfct",
					mits: ["MitCrdUtl"]
				}
			],
			/*
			*/

			/*
			*/
			pnlheadbar: {
			},

			pnlpre: {
				statshr: null
			},

			pnladmin: {
			},

			pnlglobal: {
			},

			pnlproject: {
			},

			pnldbstr: {
			},

			pnluix: {
			},

			pnlcomp: {
			},

			pnljob: {
			},

			pnldeploy: {
			},

			pnlappdev: {
			},

			pnlauxfct: {
			},

			/*
			*/

			content: {
				sref: "",
				scrJref: "",

				statshr: null,

				pnlheadbar: {
					initdone: false
				},

				initdone: false
			},

			/*
			*/
			MbarUsg: [
			],

			MbarUsr: [
				{
					sref: "MenCrd",
					mits: ["MitCrdMkp"]
				}
			],

			MbarPrs: [
			],

			MbarFil: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdDld"]
				}
			],

			MbarLoc: [
			],

			MbarTag: [
			],

			MbarCtp: [
			],

			MbarMch: [
				{
					sref: "MenCrd",
					mits: ["MitCrdWis"]
				}
			],

			MbarLib: [
			],

			MbarPrj: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdIpx"]
				}
			],

			MbarVer: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdPcv", "MitCrdIdp", "MitCrdIgb", "MitCrdImd", "MitCrdIdb", "MitCrdIbu", "MitCrdIie", "MitCrdIop", "MitCrdIcj", "MitCrdGui", "MitCrdAui", "MitCrdGjt", "MitCrdAjt", "MitCrdFnm"]
				}
			],

			MbarCap: [
			],

			MbarErr: [
			],

			MbarTbl: [
			],

			MbarTco: [
			],

			MbarSbs: [
			],

			MbarRel: [
			],

			MbarVec: [
			],

			MbarVit: [
			],

			MbarChk: [
			],

			MbarStb: [
			],

			MbarIex: [
			],

			MbarIme: [
			],

			MbarIel: [
			],

			MbarPst: [
			],

			MbarMdl: [
			],

			MbarCar: [
			],

			MbarDlg: [
			],

			MbarPnl: [
			],

			MbarQry: [
			],

			MbarQco: [
			],

			MbarQmd: [
			],

			MbarCon: [
			],

			MbarOpk: [
			],

			MbarOpx: [
			],

			MbarJob: [
			],

			MbarSge: [
			],

			MbarMtd: [
			],

			MbarBlk: [
			],

			MbarCal: [
			],

			MbarCmp: [
			],

			MbarRls: [
				{
					sref: "MenCrd",
					mits: ["MitCrdSrt", "MitCrdCrt", "MitCrdFrt", "MitCrdWco"]
				}
			],

			MbarApp: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdIst", "MitCrdWrc"]
				}
			],

			MbarRtj: [
			],

			MbarEvt: [
			],

			MbarSeq: [
			],

			MbarSte: [
			],

			MbarUtl: [
				{
					sref: "MenCrd",
					mits: ["MitCrdXip", "MitCrdMip"]
				}
			],

			/*
			*/

			MbarContent: null,

			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
