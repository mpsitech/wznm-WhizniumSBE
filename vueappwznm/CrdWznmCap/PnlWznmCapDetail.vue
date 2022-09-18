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
				v-model="continf.TxtTpl"
				:label="tag.CptTpl"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstAtf"
				multiple
				return-object
				:items="feedFLstAtf"
				item-value="num"
				item-text="tit1"
				:label="tag.CptAtf"
				v-on:change="handleFisChange('numsFLstAtf', contapp.fisFLstAtf)"
				:disabled="!statshr.LstAtfActive"
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
		name: 'PnlWznmCapDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmCapDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCapDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmCapDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmCapDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmCapDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmCapDetail) this.contiac = dpcheng.ContIacWznmCapDetail;
				if (dpcheng.ContInfWznmCapDetail) this.continf = dpcheng.ContInfWznmCapDetail;
				if (dpcheng.FeedFLstAtf) this.feedFLstAtf = dpcheng.FeedFLstAtf;
				if (dpcheng.StatAppWznmCapDetail) this.statapp = dpcheng.StatAppWznmCapDetail;
				if (dpcheng.StatShrWznmCapDetail) this.statshr = dpcheng.StatShrWznmCapDetail;
				if (dpcheng.TagWznmCapDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmCapDetail);
					this.tag = dpcheng.TagWznmCapDetail;
				}
				if (dpcheng.ContIacWznmCapDetail) {
					var fisFLstAtf = [];
					var numsFLstAtf = vecio.parseUintvec(this.contiac.numsFLstAtf);

					for (let i = 0; i < this.feedFLstAtf.length; i++)
						if (numsFLstAtf.includes(this.feedFLstAtf[i].num))
							fisFLstAtf.push(this.feedFLstAtf[i]);

					this.contapp.fisFLstAtf = fisFLstAtf;
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
				if (srefIxWznmVDpch == "DpchEngWznmCapDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmCapDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstAtf: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fisFLstAtf: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
