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
				v-model="contapp.fisFLstRea"
				multiple
				return-object
				:items="feedFLstRea"
				item-value="num"
				item-text="tit1"
				:label="tag.CptRea"
				v-on:change="handleFisChange('numsFLstRea', contapp.fisFLstRea)"
				:disabled="!statshr.LstReaActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstWri"
				multiple
				return-object
				:items="feedFLstWri"
				item-value="num"
				item-text="tit1"
				:label="tag.CptWri"
				v-on:change="handleFisChange('numsFLstWri', contapp.fisFLstWri)"
				:disabled="!statshr.LstWriActive"
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
		name: 'PnlWznmBlkDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmBlkDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmBlkDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmBlkDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmBlkDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmBlkDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmBlkDetail) this.contiac = dpcheng.ContIacWznmBlkDetail;
				if (dpcheng.ContInfWznmBlkDetail) this.continf = dpcheng.ContInfWznmBlkDetail;
				if (dpcheng.FeedFLstRea) this.feedFLstRea = dpcheng.FeedFLstRea;
				if (dpcheng.FeedFLstWri) this.feedFLstWri = dpcheng.FeedFLstWri;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmBlkDetail) this.statapp = dpcheng.StatAppWznmBlkDetail;
				if (dpcheng.StatShrWznmBlkDetail) this.statshr = dpcheng.StatShrWznmBlkDetail;
				if (dpcheng.TagWznmBlkDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmBlkDetail);
					this.tag = dpcheng.TagWznmBlkDetail;
				}
				if (dpcheng.ContIacWznmBlkDetail) {
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
					var fisFLstRea = [];
					var numsFLstRea = vecio.parseUintvec(this.contiac.numsFLstRea);

					for (let i = 0; i < this.feedFLstRea.length; i++)
						if (numsFLstRea.includes(this.feedFLstRea[i].num))
							fisFLstRea.push(this.feedFLstRea[i]);

					this.contapp.fisFLstRea = fisFLstRea;
					var fisFLstWri = [];
					var numsFLstWri = vecio.parseUintvec(this.contiac.numsFLstWri);

					for (let i = 0; i < this.feedFLstWri.length; i++)
						if (numsFLstWri.includes(this.feedFLstWri[i].num))
							fisFLstWri.push(this.feedFLstWri[i]);

					this.contapp.fisFLstWri = fisFLstWri;
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
				if (srefIxWznmVDpch == "DpchEngWznmBlkDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmBlkDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstRea: null,

			feedFLstWri: null,

			feedFPupRet: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupRet: null,

				fisFLstRea: [],

				fisFLstWri: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
