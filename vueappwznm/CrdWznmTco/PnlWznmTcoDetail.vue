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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTbl"
				:label="tag.CptTbl"
			/>

			<v-text-field
				v-if="statshr.TxtSbsAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSbs"
				:label="tag.CptSbs"
			/>

			<v-text-field
				v-if="statshr.TxtRelAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtRel"
				:label="tag.CptRel"
			/>

			<v-text-field
				v-if="statshr.TxtFcuAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFcu"
				:label="tag.CptFcu"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSty"
				return-object
				:items="feedFPupSty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSty"
				v-on:change="handleFiChange('numFPupSty', contapp.fiFPupSty)"
				:disabled="!statshr.PupStyActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupAxf"
				return-object
				:items="feedFPupAxf"
				item-value="num"
				item-text="tit1"
				:label="tag.CptAxf"
				v-on:change="handleFiChange('numFPupAxf', contapp.fiFPupAxf)"
				:disabled="!statshr.PupAxfActive"
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

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkPnc"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptPnc"
				:disabled="!statshr.ChkPncActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkEpo"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEpo"
				:disabled="!statshr.ChkEpoActive"
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
		name: 'PnlWznmTcoDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmTcoDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTcoDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmTcoDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmTcoDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmTcoDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmTcoDetail) this.contiac = dpcheng.ContIacWznmTcoDetail;
				if (dpcheng.ContInfWznmTcoDetail) this.continf = dpcheng.ContInfWznmTcoDetail;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFPupAxf) this.feedFPupAxf = dpcheng.FeedFPupAxf;
				if (dpcheng.FeedFPupFct) this.feedFPupFct = dpcheng.FeedFPupFct;
				if (dpcheng.FeedFPupSty) this.feedFPupSty = dpcheng.FeedFPupSty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmTcoDetail) this.statapp = dpcheng.StatAppWznmTcoDetail;
				if (dpcheng.StatShrWznmTcoDetail) this.statshr = dpcheng.StatShrWznmTcoDetail;
				if (dpcheng.TagWznmTcoDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmTcoDetail);
					this.tag = dpcheng.TagWznmTcoDetail;
				}
				if (dpcheng.ContIacWznmTcoDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupFct.length; i++)
						if (this.feedFPupFct[i].num == this.contiac.numFPupFct) {
							this.contapp.fiFPupFct = this.feedFPupFct[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSty.length; i++)
						if (this.feedFPupSty[i].num == this.contiac.numFPupSty) {
							this.contapp.fiFPupSty = this.feedFPupSty[i];
							break;
						}
					for (let i = 0; i < this.feedFPupAxf.length; i++)
						if (this.feedFPupAxf[i].num == this.contiac.numFPupAxf) {
							this.contapp.fiFPupAxf = this.feedFPupAxf[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmTcoDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmTcoDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstOpt: null,

			feedFPupAxf: null,

			feedFPupFct: null,

			feedFPupSty: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupFct: null,

				fiFPupSty: null,

				fiFPupAxf: null,

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
