<template>
	<v-container v-if="initdone">
		<PnlWznmUsrList
			v-on:request="handleRequest"
			ref="PnlWznmUsrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmUsrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmUsrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmUsrList from './PnlWznmUsrList';
	import PnlWznmUsrRec from './PnlWznmUsrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmUsr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmUsrList,
			PnlWznmUsrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmUsr.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmUsr) this.continf = dpcheng.ContInfWznmUsr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmUsr) this.statapp = dpcheng.StatAppWznmUsr;
				if (dpcheng.StatShrWznmUsr) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWznmUsr.scrJrefDlgmngkeypair != "");
						dlgclose = (this.statshr.scrJrefDlgmngkeypair != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmUsr.scrJrefDlgmngkeypair != "") {
								srefDlg = "DlgWznmUsrMngkeypair";
								scrJrefDlg = dpcheng.StatShrWznmUsr.scrJrefDlgmngkeypair;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmUsr;
				}
				if (dpcheng.TagWznmUsr) {
					Wznm.unescapeBlock(dpcheng.TagWznmUsr);
					this.tag = dpcheng.TagWznmUsr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmUsrList.handleReply(obj);
					else this.$refs.PnlWznmUsrRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmUsrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmUsrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmUsrRec.handleUpdate(obj);
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
