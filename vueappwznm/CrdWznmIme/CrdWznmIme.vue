<template>
	<v-container v-if="initdone">
		<PnlWznmImeList
			v-on:request="handleRequest"
			ref="PnlWznmImeList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmImeRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmImeRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmImeList from './PnlWznmImeList';
	import PnlWznmImeRec from './PnlWznmImeRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmIme',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmImeList,
			PnlWznmImeRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmIme.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmIme) this.continf = dpcheng.ContInfWznmIme;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmIme) this.statapp = dpcheng.StatAppWznmIme;
				if (dpcheng.StatShrWznmIme) this.statshr = dpcheng.StatShrWznmIme;
				if (dpcheng.TagWznmIme) {
					Wznm.unescapeBlock(dpcheng.TagWznmIme);
					this.tag = dpcheng.TagWznmIme;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmImeList.handleReply(obj);
					else this.$refs.PnlWznmImeRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmImeData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmImeList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmImeRec.handleUpdate(obj);
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
