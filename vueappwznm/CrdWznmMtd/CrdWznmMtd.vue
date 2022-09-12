<template>
	<v-container v-if="initdone">
		<PnlWznmMtdList
			v-on:request="handleRequest"
			ref="PnlWznmMtdList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmMtdRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmMtdRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmMtdList from './PnlWznmMtdList';
	import PnlWznmMtdRec from './PnlWznmMtdRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmMtd',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmMtdList,
			PnlWznmMtdRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmMtd.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmMtd) this.continf = dpcheng.ContInfWznmMtd;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmMtd) this.statapp = dpcheng.StatAppWznmMtd;
				if (dpcheng.StatShrWznmMtd) this.statshr = dpcheng.StatShrWznmMtd;
				if (dpcheng.TagWznmMtd) {
					Wznm.unescapeBlock(dpcheng.TagWznmMtd);
					this.tag = dpcheng.TagWznmMtd;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmMtdList.handleReply(obj);
					else this.$refs.PnlWznmMtdRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmMtdData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmMtdList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmMtdRec.handleUpdate(obj);
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
