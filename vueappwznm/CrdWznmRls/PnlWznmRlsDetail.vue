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
				v-model="continf.TxtCmp"
				:label="tag.CptCmp"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtMch"
				:label="tag.CptMch"
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
		name: 'PnlWznmRlsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmRlsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmRlsDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmRlsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmRlsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmRlsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmRlsDetail) this.contiac = dpcheng.ContIacWznmRlsDetail;
				if (dpcheng.ContInfWznmRlsDetail) this.continf = dpcheng.ContInfWznmRlsDetail;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.StatAppWznmRlsDetail) this.statapp = dpcheng.StatAppWznmRlsDetail;
				if (dpcheng.StatShrWznmRlsDetail) this.statshr = dpcheng.StatShrWznmRlsDetail;
				if (dpcheng.TagWznmRlsDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmRlsDetail);
					this.tag = dpcheng.TagWznmRlsDetail;
				}
				if (dpcheng.ContIacWznmRlsDetail) {
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
				if (srefIxWznmVDpch == "DpchEngWznmRlsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmRlsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
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
