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
				v-model="continf.TxtVer"
				:label="tag.CptVer"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstIat"
				multiple
				return-object
				:items="feedFLstIat"
				item-value="num"
				item-text="tit1"
				:label="tag.CptIat"
				v-on:change="handleFisChange('numsFLstIat', contapp.fisFLstIat)"
				:disabled="!statshr.LstIatActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstRat"
				multiple
				return-object
				:items="feedFLstRat"
				item-value="num"
				item-text="tit1"
				:label="tag.CptRat"
				v-on:change="handleFisChange('numsFLstRat', contapp.fisFLstRat)"
				:disabled="!statshr.LstRatActive"
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
	import vecio from '../../scripts/vecio';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmCalDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmCalDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCalDetailDo": {
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

			handleFisChange: function(cisref, fis) {
				var nums = new Uint32Array(fis.length);

				for (let i = 0; i < fis.length; i++) nums[i] = fis[i].num;
				this.contiac[cisref] = vecio.toBase64(nums);

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmCalDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmCalDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmCalDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmCalDetail) this.contiac = dpcheng.ContIacWznmCalDetail;
				if (dpcheng.ContInfWznmCalDetail) this.continf = dpcheng.ContInfWznmCalDetail;
				if (dpcheng.FeedFLstIat) this.feedFLstIat = dpcheng.FeedFLstIat;
				if (dpcheng.FeedFLstRat) this.feedFLstRat = dpcheng.FeedFLstRat;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmCalDetail) this.statapp = dpcheng.StatAppWznmCalDetail;
				if (dpcheng.StatShrWznmCalDetail) this.statshr = dpcheng.StatShrWznmCalDetail;
				if (dpcheng.TagWznmCalDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmCalDetail);
					this.tag = dpcheng.TagWznmCalDetail;
				}
				if (dpcheng.ContIacWznmCalDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					var fisFLstIat = [];
					var numsFLstIat = vecio.parseUintvec(this.contiac.numsFLstIat);

					for (let i = 0; i < this.feedFLstIat.length; i++)
						if (numsFLstIat.includes(this.feedFLstIat[i].num))
							fisFLstIat.push(this.feedFLstIat[i]);

					this.contapp.fisFLstIat = fisFLstIat;
					var fisFLstRat = [];
					var numsFLstRat = vecio.parseUintvec(this.contiac.numsFLstRat);

					for (let i = 0; i < this.feedFLstRat.length; i++)
						if (numsFLstRat.includes(this.feedFLstRat[i].num))
							fisFLstRat.push(this.feedFLstRat[i]);

					this.contapp.fisFLstRat = fisFLstRat;
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
				if (srefIxWznmVDpch == "DpchEngWznmCalDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmCalDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstIat: null,

			feedFLstRat: null,

			feedFPupRet: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupRet: null,

				fisFLstIat: [],

				fisFLstRat: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
