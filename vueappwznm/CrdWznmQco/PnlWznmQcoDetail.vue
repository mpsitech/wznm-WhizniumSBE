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
				v-model="continf.TxtQry"
				:label="tag.CptQry"
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
				v-model="continf.TxtStb"
				:label="tag.CptStb"
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
		name: 'PnlWznmQcoDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmQcoDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmQcoDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmQcoDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmQcoDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmQcoDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmQcoDetail) this.contiac = dpcheng.ContIacWznmQcoDetail;
				if (dpcheng.ContInfWznmQcoDetail) this.continf = dpcheng.ContInfWznmQcoDetail;
				if (dpcheng.FeedFLstOcc) this.feedFLstOcc = dpcheng.FeedFLstOcc;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmQcoDetail) this.statapp = dpcheng.StatAppWznmQcoDetail;
				if (dpcheng.StatShrWznmQcoDetail) this.statshr = dpcheng.StatShrWznmQcoDetail;
				if (dpcheng.TagWznmQcoDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmQcoDetail);
					this.tag = dpcheng.TagWznmQcoDetail;
				}
				if (dpcheng.ContIacWznmQcoDetail) {
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
				if (srefIxWznmVDpch == "DpchEngWznmQcoDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmQcoDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fisFLstOcc: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
