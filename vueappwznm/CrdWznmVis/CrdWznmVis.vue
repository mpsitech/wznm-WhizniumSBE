<template>
	<v-container v-if="initdone">
		<PnlWznmVisList
			v-on:request="handleRequest"
			ref="PnlWznmVisList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmVisRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmVisRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmVisList from './PnlWznmVisList';
	import PnlWznmVisRec from './PnlWznmVisRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmVis',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmVisList,
			PnlWznmVisRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmVis.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmVis) this.continf = dpcheng.ContInfWznmVis;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmVis) this.statapp = dpcheng.StatAppWznmVis;
				if (dpcheng.StatShrWznmVis) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmVis.scrJrefDlgexpstr != "") || (dpcheng.StatShrWznmVis.scrJrefDlgimpstr != "") || (dpcheng.StatShrWznmVis.scrJrefDlgmissfeat != "") || (dpcheng.StatShrWznmVis.scrJrefDlgnew != "") || (dpcheng.StatShrWznmVis.scrJrefDlgwrite != ""));
						dlgclose = ((this.statshr.scrJrefDlgexpstr != "") || (this.statshr.scrJrefDlgimpstr != "") || (this.statshr.scrJrefDlgmissfeat != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgwrite != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmVis.scrJrefDlgexpstr != "") {
								srefDlg = "DlgWznmVisExpstr";
								scrJrefDlg = dpcheng.StatShrWznmVis.scrJrefDlgexpstr;
							} else if (dpcheng.StatShrWznmVis.scrJrefDlgimpstr != "") {
								srefDlg = "DlgWznmVisImpstr";
								scrJrefDlg = dpcheng.StatShrWznmVis.scrJrefDlgimpstr;
							} else if (dpcheng.StatShrWznmVis.scrJrefDlgmissfeat != "") {
								srefDlg = "DlgWznmVisMissfeat";
								scrJrefDlg = dpcheng.StatShrWznmVis.scrJrefDlgmissfeat;
							} else if (dpcheng.StatShrWznmVis.scrJrefDlgnew != "") {
								srefDlg = "DlgWznmVisNew";
								scrJrefDlg = dpcheng.StatShrWznmVis.scrJrefDlgnew;
							} else if (dpcheng.StatShrWznmVis.scrJrefDlgwrite != "") {
								srefDlg = "DlgWznmVisWrite";
								scrJrefDlg = dpcheng.StatShrWznmVis.scrJrefDlgwrite;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmVis;
				}
				if (dpcheng.TagWznmVis) {
					Wznm.unescapeBlock(dpcheng.TagWznmVis);
					this.tag = dpcheng.TagWznmVis;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmVisList.handleReply(obj);
					else this.$refs.PnlWznmVisRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmVisData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmVisList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmVisRec.handleUpdate(obj);
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
