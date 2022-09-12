<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<div
				class="my-1"
			>
				<!-- IP divJ - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTit"
				:label="tag.CptTit"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtVec"
				:label="tag.CptVec"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAvl"
				:label="tag.CptAvl"
				:disabled="!statshr.TxfAvlActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfImp"
				:label="tag.CptImp"
				:disabled="!statshr.TxfImpActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
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
		name: 'PnlWznmVitDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmVitDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmVitDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmVitDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmVitDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmVitDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmVitDetail) this.contiac = dpcheng.ContIacWznmVitDetail;
				if (dpcheng.ContInfWznmVitDetail) this.continf = dpcheng.ContInfWznmVitDetail;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.StatAppWznmVitDetail) this.statapp = dpcheng.StatAppWznmVitDetail;
				if (dpcheng.StatShrWznmVitDetail) this.statshr = dpcheng.StatShrWznmVitDetail;
				if (dpcheng.TagWznmVitDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmVitDetail);
					this.tag = dpcheng.TagWznmVitDetail;
				}
				if (dpcheng.ContIacWznmVitDetail) {
					for (let i = 0; i < this.feedFPupJ.length; i++)
						if (this.feedFPupJ[i].num == this.contiac.numFPupJ) {
							this.contapp.fiFPupJ = this.feedFPupJ[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmVitDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmVitDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupJ: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJ: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
