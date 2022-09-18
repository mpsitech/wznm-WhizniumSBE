<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrj"
				:label="tag.CptPrj"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMaj"
				:label="tag.CptMaj"
				:disabled="!statshr.TxfMajActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMin"
				:label="tag.CptMin"
				:disabled="!statshr.TxfMinActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSub"
				:label="tag.CptSub"
				:disabled="!statshr.TxfSubActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtBvr"
				:label="tag.CptBvr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLoc"
				:label="tag.CptLoc"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJst"
				return-object
				:items="feedFPupJst"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJst"
				v-on:change="handleFiChange('numFPupJst', contapp.fiFPupJst)"
				:disabled="!statshr.PupJstActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSte"
				return-object
				:items="feedFPupSte"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSte"
				v-on:change="handleFiChange('numFPupSte', contapp.fiFPupSte)"
				:disabled="!statshr.PupSteActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstDty"
				multiple
				return-object
				:items="feedFLstDty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDty"
				v-on:change="handleFisChange('numsFLstDty', contapp.fisFLstDty)"
				:disabled="!statshr.LstDtyActive"
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

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJ"
				return-object
				:items="feedFPupJ"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJ"
				v-on:change="handleFiChange('numFPupJ', contapp.fiFPupJ)"
				:disabled="!statshr.PupJActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAb1"
				:label="tag.CptAb1"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAb2"
				:label="tag.CptAb2"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAb3"
				:label="tag.CptAb3"
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
		name: 'PnlWznmVerDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmVerDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmVerDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmVerDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmVerDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmVerDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmVerDetail) this.contiac = dpcheng.ContIacWznmVerDetail;
				if (dpcheng.ContInfWznmVerDetail) this.continf = dpcheng.ContInfWznmVerDetail;
				if (dpcheng.FeedFLstDty) this.feedFLstDty = dpcheng.FeedFLstDty;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.FeedFPupJst) this.feedFPupJst = dpcheng.FeedFPupJst;
				if (dpcheng.FeedFPupSte) this.feedFPupSte = dpcheng.FeedFPupSte;
				if (dpcheng.StatAppWznmVerDetail) this.statapp = dpcheng.StatAppWznmVerDetail;
				if (dpcheng.StatShrWznmVerDetail) this.statshr = dpcheng.StatShrWznmVerDetail;
				if (dpcheng.TagWznmVerDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmVerDetail);
					this.tag = dpcheng.TagWznmVerDetail;
				}
				if (dpcheng.ContIacWznmVerDetail) {
					for (let i = 0; i < this.feedFPupJst.length; i++)
						if (this.feedFPupJst[i].num == this.contiac.numFPupJst) {
							this.contapp.fiFPupJst = this.feedFPupJst[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSte.length; i++)
						if (this.feedFPupSte[i].num == this.contiac.numFPupSte) {
							this.contapp.fiFPupSte = this.feedFPupSte[i];
							break;
						}
					var fisFLstDty = [];
					var numsFLstDty = vecio.parseUintvec(this.contiac.numsFLstDty);

					for (let i = 0; i < this.feedFLstDty.length; i++)
						if (numsFLstDty.includes(this.feedFLstDty[i].num))
							fisFLstDty.push(this.feedFLstDty[i]);

					this.contapp.fisFLstDty = fisFLstDty;
					var fisFLstOpt = [];
					var numsFLstOpt = vecio.parseUintvec(this.contiac.numsFLstOpt);

					for (let i = 0; i < this.feedFLstOpt.length; i++)
						if (numsFLstOpt.includes(this.feedFLstOpt[i].num))
							fisFLstOpt.push(this.feedFLstOpt[i]);

					this.contapp.fisFLstOpt = fisFLstOpt;
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
				if (srefIxWznmVDpch == "DpchEngWznmVerDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmVerDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDty: null,

			feedFLstOpt: null,

			feedFPupJ: null,

			feedFPupJst: null,

			feedFPupSte: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJst: null,

				fiFPupSte: null,

				fisFLstDty: [],

				fisFLstOpt: [],

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
