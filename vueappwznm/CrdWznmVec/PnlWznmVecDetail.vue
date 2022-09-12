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
				v-model="continf.TxtVer"
				:label="tag.CptVer"
			/>

			<div
				class="my-1"
			>
				<!-- IP divHku - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divTgr - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divOpt - INSERT -->
			</div>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgPst}}
			</h3>

			<v-text-field
				v-if="statshr.TxtPstSrfAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPstSrf"
				:label="tag.CptPstSrf"
			/>

			<div
				v-if="statshr.PupPstJtiAvail"
				class="my-1"
			>
				<!-- IP divPstJti - INSERT -->
			</div>

			<v-text-field
				v-if="statshr.TxtPstTitAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPstTit"
				:label="tag.CptPstTit"
			/>

			<v-text-field
				v-if="statshr.TxtPstVerAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPstVer"
				:label="tag.CptPstVer"
			/>

			<v-select
				v-if="statshr.PupPstScoAvail"
				class="my-1"
				v-model="contapp.fiFPupPstSco"
				:items="feedFPupPstSco"
				:label='tag.CptPstSco'
				v-on:change="handlePupChange('numFPupPstSco', contapp.fiFPupPstSco)"
				:disabled="!statshr.PupPstScoActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				v-if="statshr.PupPstAtyAvail"
				class="my-1"
				v-model="contapp.fiFPupPstAty"
				:items="feedFPupPstAty"
				:label='tag.CptPstAty'
				v-on:change="handlePupChange('numFPupPstAty', contapp.fiFPupPstAty)"
				:disabled="!statshr.PupPstAtyActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmVecDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmVecDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmVecDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmVecDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmVecDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmVecDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmVecDetail) this.contiac = dpcheng.ContIacWznmVecDetail;
				if (dpcheng.ContInfWznmVecDetail) this.continf = dpcheng.ContInfWznmVecDetail;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFPupHkt) this.feedFPupHkt = dpcheng.FeedFPupHkt;
				if (dpcheng.FeedFPupPstAty) this.feedFPupPstAty = dpcheng.FeedFPupPstAty;
				if (dpcheng.FeedFPupPstJti) this.feedFPupPstJti = dpcheng.FeedFPupPstJti;
				if (dpcheng.FeedFPupPstSco) this.feedFPupPstSco = dpcheng.FeedFPupPstSco;
				if (dpcheng.FeedFPupTgr) this.feedFPupTgr = dpcheng.FeedFPupTgr;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmVecDetail) this.statapp = dpcheng.StatAppWznmVecDetail;
				if (dpcheng.StatShrWznmVecDetail) this.statshr = dpcheng.StatShrWznmVecDetail;
				if (dpcheng.TagWznmVecDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmVecDetail);
					this.tag = dpcheng.TagWznmVecDetail;
				}
				if (dpcheng.ContIacWznmVecDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupHkt.length; i++)
						if (this.feedFPupHkt[i].num == this.contiac.numFPupHkt) {
							this.contapp.fiFPupHkt = this.feedFPupHkt[i];
							break;
						}
					for (let i = 0; i < this.feedFPupTgr.length; i++)
						if (this.feedFPupTgr[i].num == this.contiac.numFPupTgr) {
							this.contapp.fiFPupTgr = this.feedFPupTgr[i];
							break;
						}
					for (let i = 0; i < this.feedFPupPstJti.length; i++)
						if (this.feedFPupPstJti[i].num == this.contiac.numFPupPstJti) {
							this.contapp.fiFPupPstJti = this.feedFPupPstJti[i];
							break;
						}
					for (let i = 0; i < this.feedFPupPstSco.length; i++)
						if (this.feedFPupPstSco[i].num == this.contiac.numFPupPstSco) {
							this.contapp.fiFPupPstSco = this.feedFPupPstSco[i];
							break;
						}
					for (let i = 0; i < this.feedFPupPstAty.length; i++)
						if (this.feedFPupPstAty[i].num == this.contiac.numFPupPstAty) {
							this.contapp.fiFPupPstAty = this.feedFPupPstAty[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmVecDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmVecDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupHkt: null,

			feedFPupPstAty: null,

			feedFPupPstJti: null,

			feedFPupPstSco: null,

			feedFPupTgr: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupHkt: null,

				fiFPupTgr: null,

				fisFLstOpt: [],

				fiFPupPstJti: null,

				fiFPupPstSco: null,

				fiFPupPstAty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
