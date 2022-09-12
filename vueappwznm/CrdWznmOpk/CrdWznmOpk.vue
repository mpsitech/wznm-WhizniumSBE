<template>
	<v-container v-if="initdone">
		<PnlWznmOpkList
			v-on:request="handleRequest"
			ref="PnlWznmOpkList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmOpkRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmOpkRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmOpkList from './PnlWznmOpkList';
	import PnlWznmOpkRec from './PnlWznmOpkRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmOpk',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmOpkList,
			PnlWznmOpkRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmOpk.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmOpk) this.continf = dpcheng.ContInfWznmOpk;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmOpk) this.statapp = dpcheng.StatAppWznmOpk;
				if (dpcheng.StatShrWznmOpk) this.statshr = dpcheng.StatShrWznmOpk;
				if (dpcheng.TagWznmOpk) {
					Wznm.unescapeBlock(dpcheng.TagWznmOpk);
					this.tag = dpcheng.TagWznmOpk;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmOpkList.handleReply(obj);
					else this.$refs.PnlWznmOpkRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmOpkData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmOpkList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmOpkRec.handleUpdate(obj);
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
