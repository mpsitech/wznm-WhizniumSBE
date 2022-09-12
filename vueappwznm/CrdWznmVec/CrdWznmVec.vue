<template>
	<v-container v-if="initdone">
		<PnlWznmVecList
			v-on:request="handleRequest"
			ref="PnlWznmVecList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmVecRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmVecRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmVecList from './PnlWznmVecList';
	import PnlWznmVecRec from './PnlWznmVecRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmVec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmVecList,
			PnlWznmVecRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmVec.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmVec) this.continf = dpcheng.ContInfWznmVec;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmVec) this.statapp = dpcheng.StatAppWznmVec;
				if (dpcheng.StatShrWznmVec) this.statshr = dpcheng.StatShrWznmVec;
				if (dpcheng.TagWznmVec) {
					Wznm.unescapeBlock(dpcheng.TagWznmVec);
					this.tag = dpcheng.TagWznmVec;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmVecList.handleReply(obj);
					else this.$refs.PnlWznmVecRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmVecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmVecList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmVecRec.handleUpdate(obj);
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
