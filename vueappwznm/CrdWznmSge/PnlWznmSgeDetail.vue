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

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTyp"
				return-object
				:items="feedFPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTyp"
				v-on:change="handleFiChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtJob"
				:label="tag.CptJob"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMon"
				:label="tag.CptMon"
				:disabled="!statshr.TxfMonActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSnx"
				:label="tag.CptSnx"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFnx"
				:label="tag.CptFnx"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgSqk}}
			</h3>

			<v-select
				v-if="statshr.PupSqkJtiAvail"
				class="my-1"
				v-model="contapp.fiFPupSqkJti"
				return-object
				:items="feedFPupSqkJti"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSqkJti"
				v-on:change="handleFiChange('numFPupSqkJti', contapp.fiFPupSqkJti)"
				:disabled="!statshr.PupSqkJtiActive"
			/>

			<v-text-field
				v-if="statshr.TxtSqkTitAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSqkTit"
				:label="tag.CptSqkTit"
			/>

			<v-text-field
				v-if="statshr.TxfSqkExaAvail"
				class="my-1"
				v-model="contiac.TxfSqkExa"
				:label="tag.CptSqkExa"
				:disabled="!statshr.TxfSqkExaActive"
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
		name: 'PnlWznmSgeDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmSgeDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmSgeDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmSgeDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmSgeDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmSgeDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmSgeDetail) this.contiac = dpcheng.ContIacWznmSgeDetail;
				if (dpcheng.ContInfWznmSgeDetail) this.continf = dpcheng.ContInfWznmSgeDetail;
				if (dpcheng.FeedFPupSqkJti) this.feedFPupSqkJti = dpcheng.FeedFPupSqkJti;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmSgeDetail) this.statapp = dpcheng.StatAppWznmSgeDetail;
				if (dpcheng.StatShrWznmSgeDetail) this.statshr = dpcheng.StatShrWznmSgeDetail;
				if (dpcheng.TagWznmSgeDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmSgeDetail);
					this.tag = dpcheng.TagWznmSgeDetail;
				}
				if (dpcheng.ContIacWznmSgeDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSqkJti.length; i++)
						if (this.feedFPupSqkJti[i].num == this.contiac.numFPupSqkJti) {
							this.contapp.fiFPupSqkJti = this.feedFPupSqkJti[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmSgeDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmSgeDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupSqkJti: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupSqkJti: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
