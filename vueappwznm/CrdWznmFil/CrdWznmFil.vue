<template>
	<v-container v-if="initdone">
		<PnlWznmFilList
			v-on:request="handleRequest"
			ref="PnlWznmFilList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmFilRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmFilRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmFilList from './PnlWznmFilList';
	import PnlWznmFilRec from './PnlWznmFilRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmFil',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmFilList,
			PnlWznmFilRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmFil.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWznmFil) this.continf = dpcheng.ContInfWznmFil;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmFil) this.statapp = dpcheng.StatAppWznmFil;
				if (dpcheng.StatShrWznmFil) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWznmFil.scrJrefDlgdownload != "") || (dpcheng.StatShrWznmFil.scrJrefDlgnew != ""));
						dlgclose = ((this.statshr.scrJrefDlgdownload != "") || (this.statshr.scrJrefDlgnew != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWznmFil.scrJrefDlgdownload != "") {
								srefDlg = "DlgWznmFilDownload";
								scrJrefDlg = dpcheng.StatShrWznmFil.scrJrefDlgdownload;
							} else if (dpcheng.StatShrWznmFil.scrJrefDlgnew != "") {
								srefDlg = "DlgWznmFilNew";
								scrJrefDlg = dpcheng.StatShrWznmFil.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWznmFil;
				}
				if (dpcheng.TagWznmFil) {
					Wznm.unescapeBlock(dpcheng.TagWznmFil);
					this.tag = dpcheng.TagWznmFil;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmFilList.handleReply(obj);
					else this.$refs.PnlWznmFilRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmFilData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmFilList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmFilRec.handleUpdate(obj);
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
