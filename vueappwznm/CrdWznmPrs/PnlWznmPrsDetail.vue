<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJln"
				return-object
				:items="feedFPupJln"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJln"
				v-on:change="handleFiChange('numFPupJln', contapp.fiFPupJln)"
				:disabled="!statshr.PupJlnActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLnm"
				:label="tag.CptLnm"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstDrv"
				multiple
				return-object
				:items="feedFLstDrv"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDrv"
				v-on:change="handleFisChange('numsFLstDrv', contapp.fisFLstDrv)"
				:disabled="!statshr.LstDrvActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSex"
				return-object
				:items="feedFPupSex"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSex"
				v-on:change="handleFiChange('numFPupSex', contapp.fiFPupSex)"
				:disabled="!statshr.PupSexActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTel"
				:label="tag.CptTel"
				:disabled="!statshr.TxfTelActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfEml"
				:label="tag.CptEml"
				:disabled="!statshr.TxfEmlActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSal"
				:label="tag.CptSal"
				:disabled="!statshr.TxfSalActive"
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
		name: 'PnlWznmPrsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmPrsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmPrsDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmPrsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmPrsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmPrsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmPrsDetail) this.contiac = dpcheng.ContIacWznmPrsDetail;
				if (dpcheng.ContInfWznmPrsDetail) this.continf = dpcheng.ContInfWznmPrsDetail;
				if (dpcheng.FeedFLstDrv) this.feedFLstDrv = dpcheng.FeedFLstDrv;
				if (dpcheng.FeedFPupJln) this.feedFPupJln = dpcheng.FeedFPupJln;
				if (dpcheng.FeedFPupSex) this.feedFPupSex = dpcheng.FeedFPupSex;
				if (dpcheng.StatAppWznmPrsDetail) this.statapp = dpcheng.StatAppWznmPrsDetail;
				if (dpcheng.StatShrWznmPrsDetail) this.statshr = dpcheng.StatShrWznmPrsDetail;
				if (dpcheng.TagWznmPrsDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmPrsDetail);
					this.tag = dpcheng.TagWznmPrsDetail;
				}
				if (dpcheng.ContIacWznmPrsDetail) {
					for (let i = 0; i < this.feedFPupJln.length; i++)
						if (this.feedFPupJln[i].num == this.contiac.numFPupJln) {
							this.contapp.fiFPupJln = this.feedFPupJln[i];
							break;
						}
					var fisFLstDrv = [];
					var numsFLstDrv = vecio.parseUintvec(this.contiac.numsFLstDrv);

					for (let i = 0; i < this.feedFLstDrv.length; i++)
						if (numsFLstDrv.includes(this.feedFLstDrv[i].num))
							fisFLstDrv.push(this.feedFLstDrv[i]);

					this.contapp.fisFLstDrv = fisFLstDrv;
					for (let i = 0; i < this.feedFPupSex.length; i++)
						if (this.feedFPupSex[i].num == this.contiac.numFPupSex) {
							this.contapp.fiFPupSex = this.feedFPupSex[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmPrsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmPrsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDrv: null,

			feedFPupJln: null,

			feedFPupSex: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJln: null,

				fisFLstDrv: [],

				fiFPupSex: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
