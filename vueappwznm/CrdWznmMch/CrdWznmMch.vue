<template>
	<v-container v-if="initdone">
		<PnlWznmMchList
			v-on:request="handleRequest"
			ref="PnlWznmMchList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmMchRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmMchRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmMchList from './PnlWznmMchList';
	import PnlWznmMchRec from './PnlWznmMchRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmMch',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmMchList,
			PnlWznmMchRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmMch.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmMch) this.continf = dpcheng.ContInfWznmMch;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmMch) this.statapp = dpcheng.StatAppWznmMch;
				if (dpcheng.StatShrWznmMch) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWznmMch.scrJrefDlgwriniscr != "");
						dlgclose = (this.statshr.scrJrefDlgwriniscr != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmMch.scrJrefDlgwriniscr != "") {
								srefDlg = "DlgWznmMchWriniscr";
								scrJrefDlg = dpcheng.StatShrWznmMch.scrJrefDlgwriniscr;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmMch;
				}
				if (dpcheng.TagWznmMch) {
					Wznm.unescapeBlock(dpcheng.TagWznmMch);
					this.tag = dpcheng.TagWznmMch;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmMchList.handleReply(obj);
					else this.$refs.PnlWznmMchRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmMchData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmMchList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmMchRec.handleUpdate(obj);
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
