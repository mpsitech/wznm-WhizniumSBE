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
				v-model="contiac.TxfSho"
				:label="tag.CptSho"
				:disabled="!statshr.TxfShoActive"
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

			<v-select
				class="my-1"
				v-model="contapp.fisFLstOcc"
				multiple
				return-object
				:items="feedFLstOcc"
				item-value="num"
				item-text="tit1"
				:label="tag.CptOcc"
				v-on:change="handleFisChange('numsFLstOcc', contapp.fisFLstOcc)"
				:disabled="!statshr.LstOccActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtIme"
				:label="tag.CptIme"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTco"
				:label="tag.CptTco"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtIm2"
				:label="tag.CptIm2"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupCty"
				return-object
				:items="feedFPupCty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptCty"
				v-on:change="handleFiChange('numFPupCty', contapp.fiFPupCty)"
				:disabled="!statshr.PupCtyActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfDfv"
				:label="tag.CptDfv"
				:disabled="!statshr.TxfDfvActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPst"
				:label="tag.CptPst"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtStb"
				:label="tag.CptStb"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtVit"
				:label="tag.CptVit"
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
		name: 'PnlWznmIelDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmIelDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmIelDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmIelDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmIelDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmIelDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmIelDetail) this.contiac = dpcheng.ContIacWznmIelDetail;
				if (dpcheng.ContInfWznmIelDetail) this.continf = dpcheng.ContInfWznmIelDetail;
				if (dpcheng.FeedFLstOcc) this.feedFLstOcc = dpcheng.FeedFLstOcc;
				if (dpcheng.FeedFPupCty) this.feedFPupCty = dpcheng.FeedFPupCty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmIelDetail) this.statapp = dpcheng.StatAppWznmIelDetail;
				if (dpcheng.StatShrWznmIelDetail) this.statshr = dpcheng.StatShrWznmIelDetail;
				if (dpcheng.TagWznmIelDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmIelDetail);
					this.tag = dpcheng.TagWznmIelDetail;
				}
				if (dpcheng.ContIacWznmIelDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					var fisFLstOcc = [];
					var numsFLstOcc = vecio.parseUintvec(this.contiac.numsFLstOcc);

					for (let i = 0; i < this.feedFLstOcc.length; i++)
						if (numsFLstOcc.includes(this.feedFLstOcc[i].num))
							fisFLstOcc.push(this.feedFLstOcc[i]);

					this.contapp.fisFLstOcc = fisFLstOcc;
					for (let i = 0; i < this.feedFPupCty.length; i++)
						if (this.feedFPupCty[i].num == this.contiac.numFPupCty) {
							this.contapp.fiFPupCty = this.feedFPupCty[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmIelDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmIelDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstOcc: null,

			feedFPupCty: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fisFLstOcc: [],

				fiFPupCty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
