<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFrt"
				:label="tag.CptFrt"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFrs"
				:label="tag.CptFrs"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTot"
				:label="tag.CptTot"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTos"
				:label="tag.CptTos"
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
				v-model="contapp.fiFLstClu"
				return-object
				:items="feedFLstClu"
				item-value="num"
				item-text="tit1"
				:label="tag.CptClu"
				v-on:change="handleFiChange('numFLstClu', contapp.fiFLstClu)"
				:disabled="!statshr.LstCluActive"
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
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTbl"
				:label="tag.CptTbl"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPfx"
				:label="tag.CptPfx"
				:disabled="!statshr.TxfPfxActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstOpt"
				multiple
				return-object
				:items="feedFLstOpt"
				item-value="num"
				item-text="tit1"
				:label="tag.CptOpt"
				v-on:change="handleFisChange('numsFLstOpt', contapp.fisFLstOpt)"
				:disabled="!statshr.LstOptActive"
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
		name: 'PnlWznmRelDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmRelDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmRelDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmRelDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmRelDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmRelDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmRelDetail) this.contiac = dpcheng.ContIacWznmRelDetail;
				if (dpcheng.ContInfWznmRelDetail) this.continf = dpcheng.ContInfWznmRelDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmRelDetail) this.statapp = dpcheng.StatAppWznmRelDetail;
				if (dpcheng.StatShrWznmRelDetail) this.statshr = dpcheng.StatShrWznmRelDetail;
				if (dpcheng.TagWznmRelDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmRelDetail);
					this.tag = dpcheng.TagWznmRelDetail;
				}
				if (dpcheng.ContIacWznmRelDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
					var fisFLstOpt = [];
					var numsFLstOpt = vecio.parseUintvec(this.contiac.numsFLstOpt);

					for (let i = 0; i < this.feedFLstOpt.length; i++)
						if (numsFLstOpt.includes(this.feedFLstOpt[i].num))
							fisFLstOpt.push(this.feedFLstOpt[i]);

					this.contapp.fisFLstOpt = fisFLstOpt;
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
				if (srefIxWznmVDpch == "DpchEngWznmRelDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmRelDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstClu: null,

			feedFLstOpt: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFLstClu: null,

				fisFLstOpt: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
