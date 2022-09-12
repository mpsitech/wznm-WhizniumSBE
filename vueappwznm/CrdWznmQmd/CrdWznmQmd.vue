<template>
	<v-container v-if="initdone">
		<PnlWznmQmdList
			v-on:request="handleRequest"
			ref="PnlWznmQmdList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmQmdRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmQmdRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmQmdList from './PnlWznmQmdList';
	import PnlWznmQmdRec from './PnlWznmQmdRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmQmd',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmQmdList,
			PnlWznmQmdRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmQmd.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmQmd) this.continf = dpcheng.ContInfWznmQmd;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmQmd) this.statapp = dpcheng.StatAppWznmQmd;
				if (dpcheng.StatShrWznmQmd) this.statshr = dpcheng.StatShrWznmQmd;
				if (dpcheng.TagWznmQmd) {
					Wznm.unescapeBlock(dpcheng.TagWznmQmd);
					this.tag = dpcheng.TagWznmQmd;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmQmdList.handleReply(obj);
					else this.$refs.PnlWznmQmdRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmQmdData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmQmdList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmQmdRec.handleUpdate(obj);
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
