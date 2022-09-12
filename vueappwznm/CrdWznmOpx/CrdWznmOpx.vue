<template>
	<v-container v-if="initdone">
		<PnlWznmOpxList
			v-on:request="handleRequest"
			ref="PnlWznmOpxList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmOpxRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmOpxRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmOpxList from './PnlWznmOpxList';
	import PnlWznmOpxRec from './PnlWznmOpxRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmOpx',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmOpxList,
			PnlWznmOpxRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmOpx.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmOpx) this.continf = dpcheng.ContInfWznmOpx;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmOpx) this.statapp = dpcheng.StatAppWznmOpx;
				if (dpcheng.StatShrWznmOpx) this.statshr = dpcheng.StatShrWznmOpx;
				if (dpcheng.TagWznmOpx) {
					Wznm.unescapeBlock(dpcheng.TagWznmOpx);
					this.tag = dpcheng.TagWznmOpx;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmOpxList.handleReply(obj);
					else this.$refs.PnlWznmOpxRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmOpxData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmOpxList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmOpxRec.handleUpdate(obj);
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
