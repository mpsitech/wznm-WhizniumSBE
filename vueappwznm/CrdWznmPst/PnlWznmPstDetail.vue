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

			<div
				class="my-1"
			>
				<!-- IP divJti - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTit"
				:label="tag.CptTit"
			/>

			<v-divider/>

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
				<!-- IP divReu - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSco"
				:items="feedFPupSco"
				:label='tag.CptSco'
				v-on:change="handlePupChange('numFPupSco', contapp.fiFPupSco)"
				:disabled="!statshr.PupScoActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupAty"
				:items="feedFPupAty"
				:label='tag.CptAty'
				v-on:change="handlePupChange('numFPupAty', contapp.fiFPupAty)"
				:disabled="!statshr.PupAtyActive"
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
		name: 'PnlWznmPstDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmPstDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmPstDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmPstDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmPstDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmPstDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmPstDetail) this.contiac = dpcheng.ContIacWznmPstDetail;
				if (dpcheng.ContInfWznmPstDetail) this.continf = dpcheng.ContInfWznmPstDetail;
				if (dpcheng.FeedFPupAty) this.feedFPupAty = dpcheng.FeedFPupAty;
				if (dpcheng.FeedFPupJti) this.feedFPupJti = dpcheng.FeedFPupJti;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupSco) this.feedFPupSco = dpcheng.FeedFPupSco;
				if (dpcheng.StatAppWznmPstDetail) this.statapp = dpcheng.StatAppWznmPstDetail;
				if (dpcheng.StatShrWznmPstDetail) this.statshr = dpcheng.StatShrWznmPstDetail;
				if (dpcheng.TagWznmPstDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmPstDetail);
					this.tag = dpcheng.TagWznmPstDetail;
				}
				if (dpcheng.ContIacWznmPstDetail) {
					for (let i = 0; i < this.feedFPupJti.length; i++)
						if (this.feedFPupJti[i].num == this.contiac.numFPupJti) {
							this.contapp.fiFPupJti = this.feedFPupJti[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSco.length; i++)
						if (this.feedFPupSco[i].num == this.contiac.numFPupSco) {
							this.contapp.fiFPupSco = this.feedFPupSco[i];
							break;
						}
					for (let i = 0; i < this.feedFPupAty.length; i++)
						if (this.feedFPupAty[i].num == this.contiac.numFPupAty) {
							this.contapp.fiFPupAty = this.feedFPupAty[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmPstDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmPstDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupAty: null,

			feedFPupJti: null,

			feedFPupRet: null,

			feedFPupSco: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJti: null,

				fiFPupRet: null,

				fiFPupSco: null,

				fiFPupAty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
