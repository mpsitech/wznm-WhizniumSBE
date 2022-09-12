<template>
	<v-container v-if="initdone">
		<PnlWznmBlkList
			v-on:request="handleRequest"
			ref="PnlWznmBlkList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmBlkRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmBlkRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmBlkList from './PnlWznmBlkList';
	import PnlWznmBlkRec from './PnlWznmBlkRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmBlk',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmBlkList,
			PnlWznmBlkRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmBlk.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmBlk) this.continf = dpcheng.ContInfWznmBlk;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmBlk) this.statapp = dpcheng.StatAppWznmBlk;
				if (dpcheng.StatShrWznmBlk) this.statshr = dpcheng.StatShrWznmBlk;
				if (dpcheng.TagWznmBlk) {
					Wznm.unescapeBlock(dpcheng.TagWznmBlk);
					this.tag = dpcheng.TagWznmBlk;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmBlkList.handleReply(obj);
					else this.$refs.PnlWznmBlkRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmBlkData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmBlkList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmBlkRec.handleUpdate(obj);
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
