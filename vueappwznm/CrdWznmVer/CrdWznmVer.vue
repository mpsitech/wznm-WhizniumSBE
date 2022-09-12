<template>
	<v-container v-if="initdone">
		<PnlWznmVerList
			v-on:request="handleRequest"
			ref="PnlWznmVerList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmVerRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmVerRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmVerList from './PnlWznmVerList';
	import PnlWznmVerRec from './PnlWznmVerRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmVer',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmVerList,
			PnlWznmVerRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmVer.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmVer) this.continf = dpcheng.ContInfWznmVer;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmVer) this.statapp = dpcheng.StatAppWznmVer;
				if (dpcheng.StatShrWznmVer) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmVer.scrJrefDlgbscui != "") || (dpcheng.StatShrWznmVer.scrJrefDlgcustjob != "") || (dpcheng.StatShrWznmVer.scrJrefDlgcustjtr != "") || (dpcheng.StatShrWznmVer.scrJrefDlgcustui != "") || (dpcheng.StatShrWznmVer.scrJrefDlgdbstr != "") || (dpcheng.StatShrWznmVer.scrJrefDlgdeploy != "") || (dpcheng.StatShrWznmVer.scrJrefDlgfinmod != "") || (dpcheng.StatShrWznmVer.scrJrefDlggenjtr != "") || (dpcheng.StatShrWznmVer.scrJrefDlggenui != "") || (dpcheng.StatShrWznmVer.scrJrefDlgglobal != "") || (dpcheng.StatShrWznmVer.scrJrefDlgimpexp != "") || (dpcheng.StatShrWznmVer.scrJrefDlgnew != "") || (dpcheng.StatShrWznmVer.scrJrefDlgoppack != "") || (dpcheng.StatShrWznmVer.scrJrefDlgwrinimdl != ""));
						dlgclose = ((this.statshr.scrJrefDlgbscui != "") || (this.statshr.scrJrefDlgcustjob != "") || (this.statshr.scrJrefDlgcustjtr != "") || (this.statshr.scrJrefDlgcustui != "") || (this.statshr.scrJrefDlgdbstr != "") || (this.statshr.scrJrefDlgdeploy != "") || (this.statshr.scrJrefDlgfinmod != "") || (this.statshr.scrJrefDlggenjtr != "") || (this.statshr.scrJrefDlggenui != "") || (this.statshr.scrJrefDlgglobal != "") || (this.statshr.scrJrefDlgimpexp != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgoppack != "") || (this.statshr.scrJrefDlgwrinimdl != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmVer.scrJrefDlgbscui != "") {
								srefDlg = "DlgWznmVerBscui";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgbscui;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgcustjob != "") {
								srefDlg = "DlgWznmVerCustjob";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgcustjob;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgcustjtr != "") {
								srefDlg = "DlgWznmVerCustjtr";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgcustjtr;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgcustui != "") {
								srefDlg = "DlgWznmVerCustui";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgcustui;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgdbstr != "") {
								srefDlg = "DlgWznmVerDbstr";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgdbstr;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgdeploy != "") {
								srefDlg = "DlgWznmVerDeploy";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgdeploy;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgfinmod != "") {
								srefDlg = "DlgWznmVerFinmod";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgfinmod;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlggenjtr != "") {
								srefDlg = "DlgWznmVerGenjtr";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlggenjtr;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlggenui != "") {
								srefDlg = "DlgWznmVerGenui";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlggenui;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgglobal != "") {
								srefDlg = "DlgWznmVerGlobal";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgglobal;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgimpexp != "") {
								srefDlg = "DlgWznmVerImpexp";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgimpexp;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgnew != "") {
								srefDlg = "DlgWznmVerNew";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgnew;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgoppack != "") {
								srefDlg = "DlgWznmVerOppack";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgoppack;
							} else if (dpcheng.StatShrWznmVer.scrJrefDlgwrinimdl != "") {
								srefDlg = "DlgWznmVerWrinimdl";
								scrJrefDlg = dpcheng.StatShrWznmVer.scrJrefDlgwrinimdl;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmVer;
				}
				if (dpcheng.TagWznmVer) {
					Wznm.unescapeBlock(dpcheng.TagWznmVer);
					this.tag = dpcheng.TagWznmVer;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmVerList.handleReply(obj);
					else this.$refs.PnlWznmVerRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmVerData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmVerList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmVerRec.handleUpdate(obj);
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
