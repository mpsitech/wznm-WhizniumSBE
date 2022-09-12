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
				v-model="continf.TxtCar"
				:label="tag.CptCar"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCnd"
				:label="tag.CptCnd"
				:disabled="!statshr.TxfCndActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

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
		name: 'PnlWznmSbsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmSbsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmSbsDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmSbsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmSbsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmSbsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmSbsDetail) this.contiac = dpcheng.ContIacWznmSbsDetail;
				if (dpcheng.ContInfWznmSbsDetail) this.continf = dpcheng.ContInfWznmSbsDetail;
				if (dpcheng.FeedFPupPstAty) this.feedFPupPstAty = dpcheng.FeedFPupPstAty;
				if (dpcheng.FeedFPupPstJti) this.feedFPupPstJti = dpcheng.FeedFPupPstJti;
				if (dpcheng.FeedFPupPstSco) this.feedFPupPstSco = dpcheng.FeedFPupPstSco;
				if (dpcheng.StatAppWznmSbsDetail) this.statapp = dpcheng.StatAppWznmSbsDetail;
				if (dpcheng.StatShrWznmSbsDetail) this.statshr = dpcheng.StatShrWznmSbsDetail;
				if (dpcheng.TagWznmSbsDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmSbsDetail);
					this.tag = dpcheng.TagWznmSbsDetail;
				}
				if (dpcheng.ContIacWznmSbsDetail) {
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
				if (srefIxWznmVDpch == "DpchEngWznmSbsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmSbsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupPstAty: null,

			feedFPupPstJti: null,

			feedFPupPstSco: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
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
