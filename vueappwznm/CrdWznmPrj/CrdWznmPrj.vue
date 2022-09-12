<template>
	<v-container v-if="initdone">
		<PnlWznmPrjList
			v-on:request="handleRequest"
			ref="PnlWznmPrjList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmPrjRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmPrjRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmPrjList from './PnlWznmPrjList';
	import PnlWznmPrjRec from './PnlWznmPrjRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmPrj',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmPrjList,
			PnlWznmPrjRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmPrj.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmPrj) this.continf = dpcheng.ContInfWznmPrj;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmPrj) this.statapp = dpcheng.StatAppWznmPrj;
				if (dpcheng.StatShrWznmPrj) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmPrj.scrJrefDlgimpex != "") || (dpcheng.StatShrWznmPrj.scrJrefDlgnew != ""));
						dlgclose = ((this.statshr.scrJrefDlgimpex != "") || (this.statshr.scrJrefDlgnew != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmPrj.scrJrefDlgimpex != "") {
								srefDlg = "DlgWznmPrjImpex";
								scrJrefDlg = dpcheng.StatShrWznmPrj.scrJrefDlgimpex;
							} else if (dpcheng.StatShrWznmPrj.scrJrefDlgnew != "") {
								srefDlg = "DlgWznmPrjNew";
								scrJrefDlg = dpcheng.StatShrWznmPrj.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmPrj;
				}
				if (dpcheng.TagWznmPrj) {
					Wznm.unescapeBlock(dpcheng.TagWznmPrj);
					this.tag = dpcheng.TagWznmPrj;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmPrjList.handleReply(obj);
					else this.$refs.PnlWznmPrjRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmPrjData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmPrjList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmPrjRec.handleUpdate(obj);
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
