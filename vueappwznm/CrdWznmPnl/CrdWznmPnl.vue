<template>
	<v-container v-if="initdone">
		<PnlWznmPnlList
			v-on:request="handleRequest"
			ref="PnlWznmPnlList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmPnlRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmPnlRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmPnlList from './PnlWznmPnlList';
	import PnlWznmPnlRec from './PnlWznmPnlRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmPnl',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmPnlList,
			PnlWznmPnlRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmPnl.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmPnl) this.continf = dpcheng.ContInfWznmPnl;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmPnl) this.statapp = dpcheng.StatAppWznmPnl;
				if (dpcheng.StatShrWznmPnl) this.statshr = dpcheng.StatShrWznmPnl;
				if (dpcheng.TagWznmPnl) {
					Wznm.unescapeBlock(dpcheng.TagWznmPnl);
					this.tag = dpcheng.TagWznmPnl;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmPnlList.handleReply(obj);
					else this.$refs.PnlWznmPnlRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmPnlData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmPnlList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmPnlRec.handleUpdate(obj);
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
