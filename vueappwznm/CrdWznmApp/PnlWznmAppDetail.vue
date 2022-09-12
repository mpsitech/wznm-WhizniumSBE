<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfSho"
				:label="tag.CptSho"
				:disabled="!statshr.TxfShoActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTrg"
				:items="feedFPupTrg"
				:label='tag.CptTrg'
				v-on:change="handlePupChange('numFPupTrg', contapp.fiFPupTrg)"
				:disabled="!statshr.PupTrgActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtVer"
				:label="tag.CptVer"
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

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmAppDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmAppDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmAppDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmAppDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmAppDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmAppDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmAppDetail) this.contiac = dpcheng.ContIacWznmAppDetail;
				if (dpcheng.ContInfWznmAppDetail) this.continf = dpcheng.ContInfWznmAppDetail;
				if (dpcheng.FeedFPupTrg) this.feedFPupTrg = dpcheng.FeedFPupTrg;
				if (dpcheng.StatAppWznmAppDetail) this.statapp = dpcheng.StatAppWznmAppDetail;
				if (dpcheng.StatShrWznmAppDetail) this.statshr = dpcheng.StatShrWznmAppDetail;
				if (dpcheng.TagWznmAppDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmAppDetail);
					this.tag = dpcheng.TagWznmAppDetail;
				}
				if (dpcheng.ContIacWznmAppDetail) {
					for (let i = 0; i < this.feedFPupTrg.length; i++)
						if (this.feedFPupTrg[i].num == this.contiac.numFPupTrg) {
							this.contapp.fiFPupTrg = this.feedFPupTrg[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmAppDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmAppDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupTrg: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTrg: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
