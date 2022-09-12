<template>
	<v-container v-if="initdone">
		<PnlWznmCmpList
			v-on:request="handleRequest"
			ref="PnlWznmCmpList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmCmpRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmCmpRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmCmpList from './PnlWznmCmpList';
	import PnlWznmCmpRec from './PnlWznmCmpRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmCmp',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmCmpList,
			PnlWznmCmpRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmCmp.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmCmp) this.continf = dpcheng.ContInfWznmCmp;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmCmp) this.statapp = dpcheng.StatAppWznmCmp;
				if (dpcheng.StatShrWznmCmp) this.statshr = dpcheng.StatShrWznmCmp;
				if (dpcheng.TagWznmCmp) {
					Wznm.unescapeBlock(dpcheng.TagWznmCmp);
					this.tag = dpcheng.TagWznmCmp;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmCmpList.handleReply(obj);
					else this.$refs.PnlWznmCmpRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmCmpData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmCmpList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmCmpRec.handleUpdate(obj);
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
