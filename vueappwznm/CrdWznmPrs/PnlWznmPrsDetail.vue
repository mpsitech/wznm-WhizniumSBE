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

			<div
				class="my-1"
			>
				<!-- IP divJln - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLnm"
				:label="tag.CptLnm"
			/>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divDrv - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSex"
				:items="feedFPupSex"
				:label='tag.CptSex'
				v-on:change="handlePupChange('numFPupSex', contapp.fiFPupSex)"
				:disabled="!statshr.PupSexActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

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

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

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
