<template>
	<v-container v-if="initdone">
		<PnlWznmEvtList
			v-on:request="handleRequest"
			ref="PnlWznmEvtList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmEvtRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmEvtRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmEvtList from './PnlWznmEvtList';
	import PnlWznmEvtRec from './PnlWznmEvtRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmEvt',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmEvtList,
			PnlWznmEvtRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmEvt.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmEvt) this.continf = dpcheng.ContInfWznmEvt;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmEvt) this.statapp = dpcheng.StatAppWznmEvt;
				if (dpcheng.StatShrWznmEvt) this.statshr = dpcheng.StatShrWznmEvt;
				if (dpcheng.TagWznmEvt) {
					Wznm.unescapeBlock(dpcheng.TagWznmEvt);
					this.tag = dpcheng.TagWznmEvt;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmEvtList.handleReply(obj);
					else this.$refs.PnlWznmEvtRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmEvtData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmEvtList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmEvtRec.handleUpdate(obj);
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
