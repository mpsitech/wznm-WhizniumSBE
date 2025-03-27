<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSht"
				:label="tag.CptSht"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtUnv"
				:label="tag.CptUnv"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfX"
				:label="tag.CptX"
				:disabled="!statshr.TxfXActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfY"
				:label="tag.CptY"
				:disabled="!statshr.TxfYActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmBoxDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmBoxDetail.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWznmBoxDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmBoxDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmBoxDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmBoxDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmBoxDetail) this.contiac = dpcheng.ContIacWznmBoxDetail;
				if (dpcheng.ContInfWznmBoxDetail) this.continf = dpcheng.ContInfWznmBoxDetail;
				if (dpcheng.FeedFPupY) this.feedFPupY = dpcheng.FeedFPupY;
				if (dpcheng.StatAppWznmBoxDetail) this.statapp = dpcheng.StatAppWznmBoxDetail;
				if (dpcheng.StatShrWznmBoxDetail) this.statshr = dpcheng.StatShrWznmBoxDetail;
				if (dpcheng.TagWznmBoxDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmBoxDetail);
					this.tag = dpcheng.TagWznmBoxDetail;
				}
				if (dpcheng.ContIacWznmBoxDetail) {
					for (let i = 0; i < this.feedFPupY.length; i++)
						if (this.feedFPupY[i].num == this.contiac.numFPupY) {
							this.contapp.fiFPupY = this.feedFPupY[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmBoxDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmBoxDetailData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFPupY: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupY: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
