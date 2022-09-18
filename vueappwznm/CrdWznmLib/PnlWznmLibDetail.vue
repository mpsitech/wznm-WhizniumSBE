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

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfVer"
				:label="tag.CptVer"
				:disabled="!statshr.TxfVerActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupLty"
				return-object
				:items="feedFPupLty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptLty"
				v-on:change="handleFiChange('numFPupLty', contapp.fiFPupLty)"
				:disabled="!statshr.PupLtyActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstDep"
				return-object
				:items="feedFLstDep"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDep"
				v-on:change="handleFiChange('numFLstDep', contapp.fiFLstDep)"
				:disabled="!statshr.LstDepActive"
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
		name: 'PnlWznmLibDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmLibDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmLibDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmLibDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmLibDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmLibDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmLibDetail) this.contiac = dpcheng.ContIacWznmLibDetail;
				if (dpcheng.ContInfWznmLibDetail) this.continf = dpcheng.ContInfWznmLibDetail;
				if (dpcheng.FeedFLstDep) this.feedFLstDep = dpcheng.FeedFLstDep;
				if (dpcheng.FeedFPupLty) this.feedFPupLty = dpcheng.FeedFPupLty;
				if (dpcheng.StatAppWznmLibDetail) this.statapp = dpcheng.StatAppWznmLibDetail;
				if (dpcheng.StatShrWznmLibDetail) this.statshr = dpcheng.StatShrWznmLibDetail;
				if (dpcheng.TagWznmLibDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmLibDetail);
					this.tag = dpcheng.TagWznmLibDetail;
				}
				if (dpcheng.ContIacWznmLibDetail) {
					for (let i = 0; i < this.feedFPupLty.length; i++)
						if (this.feedFPupLty[i].num == this.contiac.numFPupLty) {
							this.contapp.fiFPupLty = this.feedFPupLty[i];
							break;
						}
					for (let i = 0; i < this.feedFLstDep.length; i++)
						if (this.feedFLstDep[i].num == this.contiac.numFLstDep) {
							this.contapp.fiFLstDep = this.feedFLstDep[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmLibDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmLibDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDep: null,

			feedFPupLty: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupLty: null,

				fiFLstDep: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
