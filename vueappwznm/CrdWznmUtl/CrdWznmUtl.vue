<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Utilities</h1>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmUtl',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmUtl.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmUtl) this.continf = dpcheng.ContInfWznmUtl;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmUtl) this.statapp = dpcheng.StatAppWznmUtl;
				if (dpcheng.StatShrWznmUtl) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmUtl.scrJrefDlgextrip != "") || (dpcheng.StatShrWznmUtl.scrJrefDlgmrgip != ""));
						dlgclose = ((this.statshr.scrJrefDlgextrip != "") || (this.statshr.scrJrefDlgmrgip != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmUtl.scrJrefDlgextrip != "") {
								srefDlg = "DlgWznmUtlExtrip";
								scrJrefDlg = dpcheng.StatShrWznmUtl.scrJrefDlgextrip;
							} else if (dpcheng.StatShrWznmUtl.scrJrefDlgmrgip != "") {
								srefDlg = "DlgWznmUtlMrgip";
								scrJrefDlg = dpcheng.StatShrWznmUtl.scrJrefDlgmrgip;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmUtl;
				}
				if (dpcheng.TagWznmUtl) {
					Wznm.unescapeBlock(dpcheng.TagWznmUtl);
					this.tag = dpcheng.TagWznmUtl;
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
					console.log("got a '" + obj.srefIxWznmVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmUtlData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					
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
