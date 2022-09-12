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
				v-if="statshr.TxtSbsAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSbs"
				:label="tag.CptSbs"
			/>

			<v-text-field
				v-if="statshr.TxtRelAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtRel"
				:label="tag.CptRel"
			/>

			<div
				v-if="statshr.TxtFcuAvail"
				class="my-1"
			>
				<!-- IP divFcu - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSty"
				:items="feedFPupSty"
				:label='tag.CptSty'
				v-on:change="handlePupChange('numFPupSty', contapp.fiFPupSty)"
				:disabled="!statshr.PupStyActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupAxf"
				:items="feedFPupAxf"
				:label='tag.CptAxf'
				v-on:change="handlePupChange('numFPupAxf', contapp.fiFPupAxf)"
				:disabled="!statshr.PupAxfActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divOpt - INSERT -->
			</div>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkPnc"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptPnc"
				:disabled="!statshr.ChkPncActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkEpo"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEpo"
				:disabled="!statshr.ChkEpoActive"
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
		name: 'PnlWznmTcoDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmTcoDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTcoDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmTcoDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmTcoDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmTcoDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmTcoDetail) this.contiac = dpcheng.ContIacWznmTcoDetail;
				if (dpcheng.ContInfWznmTcoDetail) this.continf = dpcheng.ContInfWznmTcoDetail;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFPupAxf) this.feedFPupAxf = dpcheng.FeedFPupAxf;
				if (dpcheng.FeedFPupFct) this.feedFPupFct = dpcheng.FeedFPupFct;
				if (dpcheng.FeedFPupSty) this.feedFPupSty = dpcheng.FeedFPupSty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmTcoDetail) this.statapp = dpcheng.StatAppWznmTcoDetail;
				if (dpcheng.StatShrWznmTcoDetail) this.statshr = dpcheng.StatShrWznmTcoDetail;
				if (dpcheng.TagWznmTcoDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmTcoDetail);
					this.tag = dpcheng.TagWznmTcoDetail;
				}
				if (dpcheng.ContIacWznmTcoDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupFct.length; i++)
						if (this.feedFPupFct[i].num == this.contiac.numFPupFct) {
							this.contapp.fiFPupFct = this.feedFPupFct[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSty.length; i++)
						if (this.feedFPupSty[i].num == this.contiac.numFPupSty) {
							this.contapp.fiFPupSty = this.feedFPupSty[i];
							break;
						}
					for (let i = 0; i < this.feedFPupAxf.length; i++)
						if (this.feedFPupAxf[i].num == this.contiac.numFPupAxf) {
							this.contapp.fiFPupAxf = this.feedFPupAxf[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmTcoDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmTcoDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupAxf: null,

			feedFPupFct: null,

			feedFPupSty: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupFct: null,

				fiFPupSty: null,

				fiFPupAxf: null,

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
