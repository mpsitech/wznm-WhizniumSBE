<template>
	<v-container v-if="initdone">
		<PnlWznmTagList
			v-on:request="handleRequest"
			ref="PnlWznmTagList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmTagRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmTagRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmTagList from './PnlWznmTagList';
	import PnlWznmTagRec from './PnlWznmTagRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmTag',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmTagList,
			PnlWznmTagRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmTag.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmTag) this.continf = dpcheng.ContInfWznmTag;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmTag) this.statapp = dpcheng.StatAppWznmTag;
				if (dpcheng.StatShrWznmTag) this.statshr = dpcheng.StatShrWznmTag;
				if (dpcheng.TagWznmTag) {
					Wznm.unescapeBlock(dpcheng.TagWznmTag);
					this.tag = dpcheng.TagWznmTag;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmTagList.handleReply(obj);
					else this.$refs.PnlWznmTagRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmTagData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmTagList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmTagRec.handleUpdate(obj);
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
