<template>
	<v-container v-if="initdone">
		<PnlWznmRlsList
			v-on:request="handleRequest"
			ref="PnlWznmRlsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmRlsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmRlsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmRlsList from './PnlWznmRlsList';
	import PnlWznmRlsRec from './PnlWznmRlsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmRls',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmRlsList,
			PnlWznmRlsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmRls.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmRls) this.continf = dpcheng.ContInfWznmRls;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmRls) this.statapp = dpcheng.StatAppWznmRls;
				if (dpcheng.StatShrWznmRls) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmRls.scrJrefDlgfinreptr != "") || (dpcheng.StatShrWznmRls.scrJrefDlgstareptr != "") || (dpcheng.StatShrWznmRls.scrJrefDlgwrite != ""));
						dlgclose = ((this.statshr.scrJrefDlgfinreptr != "") || (this.statshr.scrJrefDlgstareptr != "") || (this.statshr.scrJrefDlgwrite != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmRls.scrJrefDlgfinreptr != "") {
								srefDlg = "DlgWznmRlsFinreptr";
								scrJrefDlg = dpcheng.StatShrWznmRls.scrJrefDlgfinreptr;
							} else if (dpcheng.StatShrWznmRls.scrJrefDlgstareptr != "") {
								srefDlg = "DlgWznmRlsStareptr";
								scrJrefDlg = dpcheng.StatShrWznmRls.scrJrefDlgstareptr;
							} else if (dpcheng.StatShrWznmRls.scrJrefDlgwrite != "") {
								srefDlg = "DlgWznmRlsWrite";
								scrJrefDlg = dpcheng.StatShrWznmRls.scrJrefDlgwrite;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmRls;
				}
				if (dpcheng.TagWznmRls) {
					Wznm.unescapeBlock(dpcheng.TagWznmRls);
					this.tag = dpcheng.TagWznmRls;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmRlsList.handleReply(obj);
					else this.$refs.PnlWznmRlsRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmRlsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmRlsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmRlsRec.handleUpdate(obj);
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
