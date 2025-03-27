<template>
	<v-layout class="fill-height">
		<v-navigation-drawer app floating width="350" class="elevation-1">
			<CrdWznmNav
				v-on:crdopen="handleCrdopen"
				v-on:dlgopen="handleDlgopen"
				v-on:dlgclose="handleDlgclose"
				v-on:request="handleRequestFromCrdnav"
				ref="CrdWznmNav"
				:scrJref=scrJrefCrdnav
			/>
		</v-navigation-drawer>
		<component
			:key="srefCrd"
			v-bind:is="content"
			v-on:crdopen="handleCrdopen"
			v-on:dlgopen="handleDlgopen"
			v-on:dlgclose="handleDlgclose"
			v-on:request="handleRequestFromCrd"
			v-on:upload="handleUpload"
			ref="content"
			:scrJref=scrJrefCrd
		/>
		<v-dialog
			v-model="alert"
			v-if="alert"
			persistent
			width="500"
		>
			<v-card>
				<v-card-title>
					{{alert.TxtCpt}}
				</v-card-title>
				<v-card-text>
					<div
						v-for="(TxtMsg, ix) in alert.TxtMsgs"
						:key="ix"
					>
						{{TxtMsg ? TxtMsg : '&nbsp;'}}
					</div>
				</v-card-text>
				<v-divider/>
				<v-card-actions>
					<v-spacer/>
					<v-btn
						class="primary"
						v-for="Fi in alert.FeedFMcbAlert"
						:key="Fi.num"
						v-on:click="handleAlertAction(Fi.num)"
					>
						{{Fi.tit1}}
					</v-btn>
				</v-card-actions>
			</v-card>
		</v-dialog>
		<v-dialog
			v-model="dialog"
			v-if="dialog"
			persistent
			width="1200"
		>
			<component
				:key="srefDlg"
				v-bind:is="dialog"
				v-on:upload="handleUpload"
				v-on:request="handleRequestFromDlg"
				ref="dialog"
				:scrJref=scrJrefDlg
			/>
		</v-dialog>
	</v-layout>
</template>

<script>
	import axios from 'axios'

	import Wznm from '../scripts/Wznm';

	/*
	*/
	import CrdWznmUsg from './CrdWznmUsg/CrdWznmUsg';
	import CrdWznmUsr from './CrdWznmUsr/CrdWznmUsr';
	import DlgWznmUsrMngkeypair from './CrdWznmUsr/DlgWznmUsrMngkeypair';
	import CrdWznmPrs from './CrdWznmPrs/CrdWznmPrs';
	import CrdWznmFil from './CrdWznmFil/CrdWznmFil';
	import DlgWznmFilDownload from './CrdWznmFil/DlgWznmFilDownload';
	import DlgWznmFilNew from './CrdWznmFil/DlgWznmFilNew';
	import CrdWznmNav from './CrdWznmNav/CrdWznmNav';
	import DlgWznmNavLoaini from './CrdWznmNav/DlgWznmNavLoaini';
	import DlgWznmNavMnglic from './CrdWznmNav/DlgWznmNavMnglic';
	import CrdWznmLoc from './CrdWznmLoc/CrdWznmLoc';
	import CrdWznmTag from './CrdWznmTag/CrdWznmTag';
	import CrdWznmCtp from './CrdWznmCtp/CrdWznmCtp';
	import CrdWznmMch from './CrdWznmMch/CrdWznmMch';
	import DlgWznmMchWriniscr from './CrdWznmMch/DlgWznmMchWriniscr';
	import CrdWznmLib from './CrdWznmLib/CrdWznmLib';
	import CrdWznmPrj from './CrdWznmPrj/CrdWznmPrj';
	import DlgWznmPrjImpex from './CrdWznmPrj/DlgWznmPrjImpex';
	import DlgWznmPrjNew from './CrdWznmPrj/DlgWznmPrjNew';
	import CrdWznmVer from './CrdWznmVer/CrdWznmVer';
	import DlgWznmVerBscui from './CrdWznmVer/DlgWznmVerBscui';
	import DlgWznmVerCustjob from './CrdWznmVer/DlgWznmVerCustjob';
	import DlgWznmVerCustjtr from './CrdWznmVer/DlgWznmVerCustjtr';
	import DlgWznmVerCustui from './CrdWznmVer/DlgWznmVerCustui';
	import DlgWznmVerDbstr from './CrdWznmVer/DlgWznmVerDbstr';
	import DlgWznmVerDeploy from './CrdWznmVer/DlgWznmVerDeploy';
	import DlgWznmVerFinmod from './CrdWznmVer/DlgWznmVerFinmod';
	import DlgWznmVerGenjtr from './CrdWznmVer/DlgWznmVerGenjtr';
	import DlgWznmVerGenui from './CrdWznmVer/DlgWznmVerGenui';
	import DlgWznmVerGlobal from './CrdWznmVer/DlgWznmVerGlobal';
	import DlgWznmVerImpexp from './CrdWznmVer/DlgWznmVerImpexp';
	import DlgWznmVerNew from './CrdWznmVer/DlgWznmVerNew';
	import DlgWznmVerOppack from './CrdWznmVer/DlgWznmVerOppack';
	import DlgWznmVerWrinimdl from './CrdWznmVer/DlgWznmVerWrinimdl';
	import CrdWznmCap from './CrdWznmCap/CrdWznmCap';
	import CrdWznmErr from './CrdWznmErr/CrdWznmErr';
	import CrdWznmTbl from './CrdWznmTbl/CrdWznmTbl';
	import CrdWznmTco from './CrdWznmTco/CrdWznmTco';
	import CrdWznmSbs from './CrdWznmSbs/CrdWznmSbs';
	import CrdWznmRel from './CrdWznmRel/CrdWznmRel';
	import CrdWznmVec from './CrdWznmVec/CrdWznmVec';
	import CrdWznmVit from './CrdWznmVit/CrdWznmVit';
	import CrdWznmChk from './CrdWznmChk/CrdWznmChk';
	import CrdWznmStb from './CrdWznmStb/CrdWznmStb';
	import CrdWznmIex from './CrdWznmIex/CrdWznmIex';
	import CrdWznmIme from './CrdWznmIme/CrdWznmIme';
	import CrdWznmIel from './CrdWznmIel/CrdWznmIel';
	import CrdWznmPst from './CrdWznmPst/CrdWznmPst';
	import CrdWznmMdl from './CrdWznmMdl/CrdWznmMdl';
	import CrdWznmCar from './CrdWznmCar/CrdWznmCar';
	import CrdWznmDlg from './CrdWznmDlg/CrdWznmDlg';
	import CrdWznmPnl from './CrdWznmPnl/CrdWznmPnl';
	import CrdWznmQry from './CrdWznmQry/CrdWznmQry';
	import CrdWznmQco from './CrdWznmQco/CrdWznmQco';
	import CrdWznmQmd from './CrdWznmQmd/CrdWznmQmd';
	import CrdWznmCon from './CrdWznmCon/CrdWznmCon';
	import CrdWznmOpk from './CrdWznmOpk/CrdWznmOpk';
	import CrdWznmOpx from './CrdWznmOpx/CrdWznmOpx';
	import CrdWznmJob from './CrdWznmJob/CrdWznmJob';
	import CrdWznmSge from './CrdWznmSge/CrdWznmSge';
	import CrdWznmMtd from './CrdWznmMtd/CrdWznmMtd';
	import CrdWznmBlk from './CrdWznmBlk/CrdWznmBlk';
	import CrdWznmCal from './CrdWznmCal/CrdWznmCal';
	import CrdWznmCmp from './CrdWznmCmp/CrdWznmCmp';
	import CrdWznmRls from './CrdWznmRls/CrdWznmRls';
	import DlgWznmRlsFinreptr from './CrdWznmRls/DlgWznmRlsFinreptr';
	import DlgWznmRlsStareptr from './CrdWznmRls/DlgWznmRlsStareptr';
	import DlgWznmRlsWrite from './CrdWznmRls/DlgWznmRlsWrite';
	import CrdWznmVis from './CrdWznmVis/CrdWznmVis';
	import DlgWznmVisExpstr from './CrdWznmVis/DlgWznmVisExpstr';
	import DlgWznmVisImpstr from './CrdWznmVis/DlgWznmVisImpstr';
	import DlgWznmVisMissfeat from './CrdWznmVis/DlgWznmVisMissfeat';
	import DlgWznmVisNew from './CrdWznmVis/DlgWznmVisNew';
	import DlgWznmVisWrite from './CrdWznmVis/DlgWznmVisWrite';
	import CrdWznmSht from './CrdWznmSht/CrdWznmSht';
	import CrdWznmBox from './CrdWznmBox/CrdWznmBox';
	import CrdWznmApp from './CrdWznmApp/CrdWznmApp';
	import DlgWznmAppImpstr from './CrdWznmApp/DlgWznmAppImpstr';
	import DlgWznmAppNew from './CrdWznmApp/DlgWznmAppNew';
	import DlgWznmAppWrite from './CrdWznmApp/DlgWznmAppWrite';
	import CrdWznmRtj from './CrdWznmRtj/CrdWznmRtj';
	import CrdWznmEvt from './CrdWznmEvt/CrdWznmEvt';
	import CrdWznmSeq from './CrdWznmSeq/CrdWznmSeq';
	import CrdWznmSte from './CrdWznmSte/CrdWznmSte';
	import CrdWznmUtl from './CrdWznmUtl/CrdWznmUtl';
	import DlgWznmUtlExtrip from './CrdWznmUtl/DlgWznmUtlExtrip';
	import DlgWznmUtlMrgip from './CrdWznmUtl/DlgWznmUtlMrgip';
	/*
	*/

	const dpch = axios.create({
		baseURL: window.location.protocol + "//" + Wznm.hostname() + ":" + Wznm.appsrvport() + "/dpch"
	})

	const notify = axios.create({
		baseURL: window.location.protocol + "//" + Wznm.hostname() + ":" + Wznm.appsrvport() + "/notify/json"
	})

	export default {
		name: 'SessWznm',

		props: {
			scrJrefSess: String,
			scrJrefCrdnav: String,

			srefCrd_initial: String,
			scrJrefCrd_initial: String
		},

		components: {
			/*
			*/
			CrdWznmUsg,
			CrdWznmUsr,
			DlgWznmUsrMngkeypair,
			CrdWznmPrs,
			CrdWznmFil,
			DlgWznmFilDownload,
			DlgWznmFilNew,
			CrdWznmNav,
			DlgWznmNavLoaini,
			DlgWznmNavMnglic,
			CrdWznmLoc,
			CrdWznmTag,
			CrdWznmCtp,
			CrdWznmMch,
			DlgWznmMchWriniscr,
			CrdWznmLib,
			CrdWznmPrj,
			DlgWznmPrjImpex,
			DlgWznmPrjNew,
			CrdWznmVer,
			DlgWznmVerBscui,
			DlgWznmVerCustjob,
			DlgWznmVerCustjtr,
			DlgWznmVerCustui,
			DlgWznmVerDbstr,
			DlgWznmVerDeploy,
			DlgWznmVerFinmod,
			DlgWznmVerGenjtr,
			DlgWznmVerGenui,
			DlgWznmVerGlobal,
			DlgWznmVerImpexp,
			DlgWznmVerNew,
			DlgWznmVerOppack,
			DlgWznmVerWrinimdl,
			CrdWznmCap,
			CrdWznmErr,
			CrdWznmTbl,
			CrdWznmTco,
			CrdWznmSbs,
			CrdWznmRel,
			CrdWznmVec,
			CrdWznmVit,
			CrdWznmChk,
			CrdWznmStb,
			CrdWznmIex,
			CrdWznmIme,
			CrdWznmIel,
			CrdWznmPst,
			CrdWznmMdl,
			CrdWznmCar,
			CrdWznmDlg,
			CrdWznmPnl,
			CrdWznmQry,
			CrdWznmQco,
			CrdWznmQmd,
			CrdWznmCon,
			CrdWznmOpk,
			CrdWznmOpx,
			CrdWznmJob,
			CrdWznmSge,
			CrdWznmMtd,
			CrdWznmBlk,
			CrdWznmCal,
			CrdWznmCmp,
			CrdWznmRls,
			DlgWznmRlsFinreptr,
			DlgWznmRlsStareptr,
			DlgWznmRlsWrite,
			CrdWznmVis,
			DlgWznmVisExpstr,
			DlgWznmVisImpstr,
			DlgWznmVisMissfeat,
			DlgWznmVisNew,
			DlgWznmVisWrite,
			CrdWznmSht,
			CrdWznmBox,
			CrdWznmApp,
			DlgWznmAppImpstr,
			DlgWznmAppNew,
			DlgWznmAppWrite,
			CrdWznmRtj,
			CrdWznmEvt,
			CrdWznmSeq,
			CrdWznmSte,
			CrdWznmUtl,
			DlgWznmUtlExtrip,
			DlgWznmUtlMrgip
			/*
			*/
		},

		beforeMount() {
			this.srefCrd = this.srefCrd_initial;
			this.scrJrefCrd = this.scrJrefCrd_initial;

			this.content = this.srefCrd_initial;

			this.iterateNotify();
		},

		methods: {
			showAlert(dpcheng) {
				let continf = dpcheng.ContInfWznmAlert;

				Wznm.unescapeBlock(continf);

				dpcheng.TxtCpt = continf.TxtCpt; delete continf.TxtCpt;

				var i = 12;
				if (continf.TxtMsg12 == "") {
					i--;
					if (continf.TxtMsg11 == "") {
						i--;
						if (continf.TxtMsg10 == "") {
							i--;
							if (continf.TxtMsg9 == "") {
								i--;
								if (continf.TxtMsg8 == "") {
									i--;
									if (continf.TxtMsg7 == "") {
										i--;
										if (continf.TxtMsg6 == "") {
											i--;
											if (continf.TxtMsg5 == "") {
												i--;
												if (continf.TxtMsg4 == "") {
													i--;
													if (continf.TxtMsg3 == "") {
														i--;
														if (continf.TxtMsg2 == "") {
															i--;
															if (continf.TxtMsg1 == "") i--;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

				dpcheng.TxtMsgs = new Array();
				if (i > 0) dpcheng.TxtMsgs.push(continf.TxtMsg1);
				if (i > 1) dpcheng.TxtMsgs.push(continf.TxtMsg2);
				if (i > 2) dpcheng.TxtMsgs.push(continf.TxtMsg3);
				if (i > 3) dpcheng.TxtMsgs.push(continf.TxtMsg4);
				if (i > 4) dpcheng.TxtMsgs.push(continf.TxtMsg5);
				if (i > 5) dpcheng.TxtMsgs.push(continf.TxtMsg6);
				if (i > 6) dpcheng.TxtMsgs.push(continf.TxtMsg7);
				if (i > 7) dpcheng.TxtMsgs.push(continf.TxtMsg8);
				if (i > 8) dpcheng.TxtMsgs.push(continf.TxtMsg9);
				if (i > 9) dpcheng.TxtMsgs.push(continf.TxtMsg10);
				if (i > 10) dpcheng.TxtMsgs.push(continf.TxtMsg11);
				if (i > 11) dpcheng.TxtMsgs.push(continf.TxtMsg12);

				delete continf.TxtMsg1;
				delete continf.TxtMsg2;
				delete continf.TxtMsg3;
				delete continf.TxtMsg4;
				delete continf.TxtMsg5;
				delete continf.TxtMsg6;
				delete continf.TxtMsg7;
				delete continf.TxtMsg8;
				delete continf.TxtMsg9;
				delete continf.TxtMsg10;
				delete continf.TxtMsg11;
				delete continf.TxtMsg12;

				this.alert = dpcheng;
			},

			handleAlertAction: function(num) {
				const dpchapp = {
					"DpchAppWznmAlert": {
						"scrJref": this.alert.scrJref,
						"numFMcb": num
					}
				};
	
				this.handleRequest({scrJref: this.alert.scrJref, dpchapp: dpchapp, then: ""}, false);

				this.alert = null;

				this.$refs.CrdWznmNav.handleAlrdlgclose();
			},

			handleCrdopen: function(obj) {
				//console.log("SessWznm.handleCrdopen() with " + obj.srefCrd);

				if ((obj.srefCrd != this.content) || obj.newtabNotInplace) {
					if (!obj.newtabNotInplace) {
						//console.log("SessWznm.handleCrdopen() new card in-place");

						this.srefCrd = obj.srefCrd;
						this.scrJrefCrd = obj.scrJrefCrd;

						this.content = obj.srefCrd;

						this.$refs.CrdWznmNav.handleCrdopen(obj)

					} else {
						//console.log("SessWznm.handleCrdopen() new card in new tab");

						var paramBegin = window.location.href.indexOf("?");
						var url = window.location.href.substring(0, (paramBegin == -1) ? window.location.href.length : paramBegin);
						window.open(url + "?scrJrefCrdnav=" + this.scrJrefCrdnav + "&srefCrd=" + obj.srefCrd + "&scrJrefCrd=" + obj.scrJrefCrd, "_blank");
					}
				}
			},

			handleDlgopen: function(obj) {
				if (obj.srefDlg != this.dialog) {
					this.srefDlg = obj.srefDlg;
					this.scrJrefDlg = obj.scrJrefDlg;

					this.dialog = obj.srefDlg;
				}
			},

			handleDlgclose: function() {
				this.srefDlg = "";
				this.scrJrefDlg = "";

				this.dialog = null;

				this.$refs.CrdWznmNav.handleAlrdlgclose();
			},

			handleRequestFromCrdnav: function(obj) {
				this.handleRequest(obj, false, false);
			},

			handleRequestFromCrd: function(obj) {
				this.handleRequest(obj, false, true);
			},

			handleRequestFromDlg: function(obj) {
				this.handleRequest(obj, true, false);
			},

			handleRequest: function(obj, srcDlgNotCrd, srcCrdNotCrdnav) {
				const data = "json=" + encodeURIComponent(JSON.stringify(obj.dpchapp));

				var vm = this;

				dpch.post('', data).then(function (response) {
					const scrJref = obj.dpchapp[Object.keys(obj.dpchapp)[0]].scrJref;
					const srefIxWznmVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxWznmVDpch];

					const target = (srcDlgNotCrd) ? vm.$refs.dialog : (srcCrdNotCrdnav) ? vm.$refs.content : vm.$refs.CrdWznmNav;
					if (target) {
						target.handleReply({scrJref: scrJref, srefIxWznmVDpch: srefIxWznmVDpch, dpcheng: dpcheng, then: obj.then});
						if (dpcheng.scrJref == vm.scrJrefCrd) {
							if (target != vm.$refs.CrdWznmNav) vm.$refs.CrdWznmNav.handleUpdate({srefIxWznmVDpch: srefIxWznmVDpch, dpcheng: dpcheng});
							else if (vm.$refs.content) if (target != vm.$refs.content) vm.$refs.content.handleUpdate({srefIxWznmVDpch: srefIxWznmVDpch, dpcheng: dpcheng});
						}
					}

				}).catch(function (error) {
					console.log("SessWznm.handleRequest() error: " + error);
				});
			},

			handleUpload: function(obj) {
				var formData = new FormData()

				formData.append("file", obj.file, obj.file.name);

				axios.post(window.location.protocol + "//" + Wznm.hostname() + ":" + Wznm.appsrvport() + "/upload/" + obj.scrJref, formData).catch(function (error) {
					console.log("SessWznm.handleUpload() error: " + error);
				});
			},

			iterateNotify: function() {
				var vm = this;

				notify.get(this.scrJrefSess).then(function (response) {
					var iterate = true;

					const srefIxWznmVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxWznmVDpch];

					//console.log("SessWznm.iterateNotify() received " + srefIxWznmVDpch);

					if (dpcheng.scrJref == vm.scrJrefSess) {
						if (srefIxWznmVDpch == "DpchEngWznmConfirm")
							if (!dpcheng.accepted) {
								vm.$emit('logout');
								iterate = false;
							}

					} else if (srefIxWznmVDpch == "DpchEngWznmAlert") vm.showAlert(dpcheng);
					else {
						const target = (dpcheng.scrJref == vm.scrJrefDlg) ? vm.$refs.dialog : (dpcheng.scrJref != vm.scrJrefCrdnav) ? vm.$refs.content : vm.$refs.CrdWznmNav;
						if (target) {
							var processed = target.handleUpdate({srefIxWznmVDpch: srefIxWznmVDpch, dpcheng: dpcheng});
							if (!processed || (dpcheng.scrJref == vm.scrJrefCrd)) vm.$refs.CrdWznmNav.handleUpdate({srefIxWznmVDpch: srefIxWznmVDpch, dpcheng: dpcheng});
						}
					}

					if (iterate) vm.iterateNotify();

				}).catch(function (error) {
					console.log("SessWznm.iterateNotify() error: " + error);
				});
			}
		},

		data: () => ({
			content: "",

			srefCrd: "",
			scrJrefCrd: "",
			scrJrefDlg: "",

			alert: null,

			dialog: null
		})
	}
</script>
