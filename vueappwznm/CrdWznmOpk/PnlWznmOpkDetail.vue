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
				v-model="continf.TxtVer"
				:label="tag.CptVer"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkShd"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptShd"
				:disabled="!statshr.ChkShdActive"
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
		name: 'PnlWznmOpkDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmOpkDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmOpkDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmOpkDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmOpkDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmOpkDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmOpkDetail) this.contiac = dpcheng.ContIacWznmOpkDetail;
				if (dpcheng.ContInfWznmOpkDetail) this.continf = dpcheng.ContInfWznmOpkDetail;
				if (dpcheng.FeedFPupSqkJti) this.feedFPupSqkJti = dpcheng.FeedFPupSqkJti;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmOpkDetail) this.statapp = dpcheng.StatAppWznmOpkDetail;
				if (dpcheng.StatShrWznmOpkDetail) this.statshr = dpcheng.StatShrWznmOpkDetail;
				if (dpcheng.TagWznmOpkDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmOpkDetail);
					this.tag = dpcheng.TagWznmOpkDetail;
				}
				if (dpcheng.ContIacWznmOpkDetail) {
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
				if (srefIxWznmVDpch == "DpchEngWznmOpkDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmOpkDetailData") this.mergeDpchEngData(obj.dpcheng);
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
