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
		name: 'PnlWznmCtpDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmCtpDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCtpDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmCtpDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmCtpDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmCtpDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmCtpDetail) this.contiac = dpcheng.ContIacWznmCtpDetail;
				if (dpcheng.ContInfWznmCtpDetail) this.continf = dpcheng.ContInfWznmCtpDetail;
				if (dpcheng.FeedFLstAtf) this.feedFLstAtf = dpcheng.FeedFLstAtf;
				if (dpcheng.StatAppWznmCtpDetail) this.statapp = dpcheng.StatAppWznmCtpDetail;
				if (dpcheng.StatShrWznmCtpDetail) this.statshr = dpcheng.StatShrWznmCtpDetail;
				if (dpcheng.TagWznmCtpDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmCtpDetail);
					this.tag = dpcheng.TagWznmCtpDetail;
				}
				if (dpcheng.ContIacWznmCtpDetail) {
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
				if (srefIxWznmVDpch == "DpchEngWznmCtpDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmCtpDetailData") this.mergeDpchEngData(obj.dpcheng);
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
