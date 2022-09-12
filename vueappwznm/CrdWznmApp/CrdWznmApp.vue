<template>
	<v-container v-if="initdone">
		<PnlWznmAppList
			v-on:request="handleRequest"
			ref="PnlWznmAppList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmAppRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmAppRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmAppList from './PnlWznmAppList';
	import PnlWznmAppRec from './PnlWznmAppRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmApp',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmAppList,
			PnlWznmAppRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmApp.mounted() with scrJref = " + this.scrJref);

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

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWznmApp) this.continf = dpcheng.ContInfWznmApp;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmApp) this.statapp = dpcheng.StatAppWznmApp;
				if (dpcheng.StatShrWznmApp) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmApp.scrJrefDlgimpstr != "") || (dpcheng.StatShrWznmApp.scrJrefDlgnew != "") || (dpcheng.StatShrWznmApp.scrJrefDlgwrite != ""));
						dlgclose = ((this.statshr.scrJrefDlgimpstr != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgwrite != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmApp.scrJrefDlgimpstr != "") {
								srefDlg = "DlgWznmAppImpstr";
								scrJrefDlg = dpcheng.StatShrWznmApp.scrJrefDlgimpstr;
							} else if (dpcheng.StatShrWznmApp.scrJrefDlgnew != "") {
								srefDlg = "DlgWznmAppNew";
								scrJrefDlg = dpcheng.StatShrWznmApp.scrJrefDlgnew;
							} else if (dpcheng.StatShrWznmApp.scrJrefDlgwrite != "") {
								srefDlg = "DlgWznmAppWrite";
								scrJrefDlg = dpcheng.StatShrWznmApp.scrJrefDlgwrite;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmApp;
				}
				if (dpcheng.TagWznmApp) {
					Wznm.unescapeBlock(dpcheng.TagWznmApp);
					this.tag = dpcheng.TagWznmApp;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmAppList.handleReply(obj);
					else this.$refs.PnlWznmAppRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmAppData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmAppList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmAppRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWznmVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
