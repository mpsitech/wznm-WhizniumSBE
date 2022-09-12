<template>
	<v-container v-if="initdone">
		<PnlWznmRtjList
			v-on:request="handleRequest"
			ref="PnlWznmRtjList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmRtjRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmRtjRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmRtjList from './PnlWznmRtjList';
	import PnlWznmRtjRec from './PnlWznmRtjRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmRtj',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmRtjList,
			PnlWznmRtjRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmRtj.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmRtj) this.continf = dpcheng.ContInfWznmRtj;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmRtj) this.statapp = dpcheng.StatAppWznmRtj;
				if (dpcheng.StatShrWznmRtj) this.statshr = dpcheng.StatShrWznmRtj;
				if (dpcheng.TagWznmRtj) {
					Wznm.unescapeBlock(dpcheng.TagWznmRtj);
					this.tag = dpcheng.TagWznmRtj;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmRtjList.handleReply(obj);
					else this.$refs.PnlWznmRtjRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmRtjData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmRtjList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmRtjRec.handleUpdate(obj);
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
