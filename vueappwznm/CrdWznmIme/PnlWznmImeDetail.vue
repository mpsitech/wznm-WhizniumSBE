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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtIex"
				:label="tag.CptIex"
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

			<v-select
				class="my-1"
				v-model="contapp.fisFLstIop"
				multiple
				return-object
				:items="feedFLstIop"
				item-value="num"
				item-text="tit1"
				:label="tag.CptIop"
				v-on:change="handleFisChange('numsFLstIop', contapp.fisFLstIop)"
				:disabled="!statshr.LstIopActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstRtr"
				return-object
				:items="feedFLstRtr"
				item-value="num"
				item-text="tit1"
				:label="tag.CptRtr"
				v-on:change="handleFiChange('numFLstRtr', contapp.fiFLstRtr)"
				:disabled="!statshr.LstRtrActive"
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
		name: 'PnlWznmImeDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmImeDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmImeDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmImeDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmImeDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmImeDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmImeDetail) this.contiac = dpcheng.ContIacWznmImeDetail;
				if (dpcheng.ContInfWznmImeDetail) this.continf = dpcheng.ContInfWznmImeDetail;
				if (dpcheng.FeedFLstIop) this.feedFLstIop = dpcheng.FeedFLstIop;
				if (dpcheng.FeedFLstRtr) this.feedFLstRtr = dpcheng.FeedFLstRtr;
				if (dpcheng.StatAppWznmImeDetail) this.statapp = dpcheng.StatAppWznmImeDetail;
				if (dpcheng.StatShrWznmImeDetail) this.statshr = dpcheng.StatShrWznmImeDetail;
				if (dpcheng.TagWznmImeDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmImeDetail);
					this.tag = dpcheng.TagWznmImeDetail;
				}
				if (dpcheng.ContIacWznmImeDetail) {
					var fisFLstIop = [];
					var numsFLstIop = vecio.parseUintvec(this.contiac.numsFLstIop);

					for (let i = 0; i < this.feedFLstIop.length; i++)
						if (numsFLstIop.includes(this.feedFLstIop[i].num))
							fisFLstIop.push(this.feedFLstIop[i]);

					this.contapp.fisFLstIop = fisFLstIop;
					for (let i = 0; i < this.feedFLstRtr.length; i++)
						if (this.feedFLstRtr[i].num == this.contiac.numFLstRtr) {
							this.contapp.fiFLstRtr = this.feedFLstRtr[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmImeDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmImeDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstIop: null,

			feedFLstRtr: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fisFLstIop: [],

				fiFLstRtr: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
