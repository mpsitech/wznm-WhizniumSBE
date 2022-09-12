<template>
	<v-container v-if="initdone">
		<PnlWznmSeqList
			v-on:request="handleRequest"
			ref="PnlWznmSeqList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWznmSeqRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWznmSeqRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmSeqList from './PnlWznmSeqList';
	import PnlWznmSeqRec from './PnlWznmSeqRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWznmSeq',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmSeqList,
			PnlWznmSeqRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWznmSeq.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWznmSeq) this.continf = dpcheng.ContInfWznmSeq;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWznmSeq) this.statapp = dpcheng.StatAppWznmSeq;
				if (dpcheng.StatShrWznmSeq) this.statshr = dpcheng.StatShrWznmSeq;
				if (dpcheng.TagWznmSeq) {
					Wznm.unescapeBlock(dpcheng.TagWznmSeq);
					this.tag = dpcheng.TagWznmSeq;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWznmSeqList.handleReply(obj);
					else this.$refs.PnlWznmSeqRec.handleReply(obj);
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
					if (obj.srefIxWznmVDpch == "DpchEngWznmSeqData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWznmSeqList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWznmSeqRec.handleUpdate(obj);
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
