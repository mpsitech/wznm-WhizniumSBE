<template>
	<v-container v-if="initdone">
		<PnlWznmDlgList
			v-on:request="handleRequest"
			ref="PnlWznmDlgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmDlgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmDlgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmDlgList from './PnlWznmDlgList';
	import PnlWznmDlgRec from './PnlWznmDlgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmDlg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmDlgList,
			PnlWznmDlgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmDlg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmDlg) this.continf = dpcheng.ContInfWznmDlg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmDlg) this.statapp = dpcheng.StatAppWznmDlg;
				if (dpcheng.StatShrWznmDlg) this.statshr = dpcheng.StatShrWznmDlg;
				if (dpcheng.TagWznmDlg) {
					Wznm.unescapeBlock(dpcheng.TagWznmDlg);
					this.tag = dpcheng.TagWznmDlg;
				}
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmDlgList.handleReply(obj);
					else this.$refs.PnlWznmDlgRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmDlgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmDlgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmDlgRec.handleUpdate(obj);
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
