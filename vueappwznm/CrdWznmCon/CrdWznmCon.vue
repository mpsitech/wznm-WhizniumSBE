<template>
	<v-container v-if="initdone">
		<PnlWznmConList
			v-on:request="handleRequest"
			ref="PnlWznmConList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmConRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmConRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmConList from './PnlWznmConList';
	import PnlWznmConRec from './PnlWznmConRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmCon',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmConList,
			PnlWznmConRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmCon.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmCon) this.continf = dpcheng.ContInfWznmCon;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmCon) this.statapp = dpcheng.StatAppWznmCon;
				if (dpcheng.StatShrWznmCon) this.statshr = dpcheng.StatShrWznmCon;
				if (dpcheng.TagWznmCon) {
					Wznm.unescapeBlock(dpcheng.TagWznmCon);
					this.tag = dpcheng.TagWznmCon;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmConList.handleReply(obj);
					else this.$refs.PnlWznmConRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmConData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmConList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmConRec.handleUpdate(obj);
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
