<template>
	<v-container v-if="initdone">
		<PnlWznmSbsList
			v-on:request="handleRequest"
			ref="PnlWznmSbsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmSbsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmSbsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmSbsList from './PnlWznmSbsList';
	import PnlWznmSbsRec from './PnlWznmSbsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmSbs',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmSbsList,
			PnlWznmSbsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmSbs.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmSbs) this.continf = dpcheng.ContInfWznmSbs;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmSbs) this.statapp = dpcheng.StatAppWznmSbs;
				if (dpcheng.StatShrWznmSbs) this.statshr = dpcheng.StatShrWznmSbs;
				if (dpcheng.TagWznmSbs) {
					Wznm.unescapeBlock(dpcheng.TagWznmSbs);
					this.tag = dpcheng.TagWznmSbs;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmSbsList.handleReply(obj);
					else this.$refs.PnlWznmSbsRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmSbsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmSbsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmSbsRec.handleUpdate(obj);
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
