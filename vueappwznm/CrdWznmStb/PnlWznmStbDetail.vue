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
				:items="feedFPupTyp"
				:label='tag.CptTyp'
				v-on:change="handlePupChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTbl"
				:label="tag.CptTbl"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSbs"
				:label="tag.CptSbs"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkHrc"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptHrc"
				:disabled="!statshr.ChkHrcActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTco"
				:label="tag.CptTco"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkLcl"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptLcl"
				:disabled="!statshr.ChkLclActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfExa"
				:label="tag.CptExa"
				:disabled="!statshr.TxfExaActive"
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
		name: 'PnlWznmStbDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmStbDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmStbDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmStbDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmStbDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmStbDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmStbDetail) this.contiac = dpcheng.ContIacWznmStbDetail;
				if (dpcheng.ContInfWznmStbDetail) this.continf = dpcheng.ContInfWznmStbDetail;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmStbDetail) this.statapp = dpcheng.StatAppWznmStbDetail;
				if (dpcheng.StatShrWznmStbDetail) this.statshr = dpcheng.StatShrWznmStbDetail;
				if (dpcheng.TagWznmStbDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmStbDetail);
					this.tag = dpcheng.TagWznmStbDetail;
				}
				if (dpcheng.ContIacWznmStbDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmStbDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmStbDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
