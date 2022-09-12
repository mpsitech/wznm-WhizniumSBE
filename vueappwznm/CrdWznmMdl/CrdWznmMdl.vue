<template>
	<v-container v-if="initdone">
		<PnlWznmMdlList
			v-on:request="handleRequest"
			ref="PnlWznmMdlList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmMdlRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmMdlRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmMdlList from './PnlWznmMdlList';
	import PnlWznmMdlRec from './PnlWznmMdlRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmMdl',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmMdlList,
			PnlWznmMdlRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmMdl.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmMdl) this.continf = dpcheng.ContInfWznmMdl;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmMdl) this.statapp = dpcheng.StatAppWznmMdl;
				if (dpcheng.StatShrWznmMdl) this.statshr = dpcheng.StatShrWznmMdl;
				if (dpcheng.TagWznmMdl) {
					Wznm.unescapeBlock(dpcheng.TagWznmMdl);
					this.tag = dpcheng.TagWznmMdl;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmMdlList.handleReply(obj);
					else this.$refs.PnlWznmMdlRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmMdlData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmMdlList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmMdlRec.handleUpdate(obj);
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
