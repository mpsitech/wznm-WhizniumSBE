<template>
	<v-container v-if="initdone">
		<PnlWznmUsgList
			v-on:request="handleRequest"
			ref="PnlWznmUsgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmUsgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmUsgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmUsgList from './PnlWznmUsgList';
	import PnlWznmUsgRec from './PnlWznmUsgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmUsg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmUsgList,
			PnlWznmUsgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmUsg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmUsg) this.continf = dpcheng.ContInfWznmUsg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmUsg) this.statapp = dpcheng.StatAppWznmUsg;
				if (dpcheng.StatShrWznmUsg) this.statshr = dpcheng.StatShrWznmUsg;
				if (dpcheng.TagWznmUsg) {
					Wznm.unescapeBlock(dpcheng.TagWznmUsg);
					this.tag = dpcheng.TagWznmUsg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmUsgList.handleReply(obj);
					else this.$refs.PnlWznmUsgRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmUsgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmUsgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmUsgRec.handleUpdate(obj);
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
