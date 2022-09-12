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

			<div
				class="my-1"
			>
				<!-- IP divClu - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divHku - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

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
				v-model="contapp.fiFPupSty"
				:items="feedFPupSty"
				:label='tag.CptSty'
				v-on:change="handlePupChange('numFPupSty', contapp.fiFPupSty)"
				:disabled="!statshr.PupStyActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divTag - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSts"
				:label="tag.CptSts"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtShs"
				:label="tag.CptShs"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAvl"
				:label="tag.CptAvl"
				:disabled="!statshr.TxfAvlActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAct"
				:label="tag.CptAct"
				:disabled="!statshr.TxfActActive"
			/>

			<div
				class="my-1"
			>
				<!-- IP divOpt - INSERT -->
			</div>

			<v-divider v-if="statshr.SepFedAvail"/>

			<h3
				v-if="statshr.HdgFedAvail"
				class="text-5 my-1"
			>
				{{tag.HdgFed}}
			</h3>

			<v-text-field
				v-if="statshr.TxtFedSrfAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFedSrf"
				:label="tag.CptFedSrf"
			/>

			<div
				v-if="statshr.TxtFedSruAvail"
				class="my-1"
			>
				<!-- IP divFedSru - INSERT -->
			</div>

			<div
				v-if="statshr.LstFedVitAvail"
				class="my-1"
			>
				<!-- IP divFedVit - INSERT -->
			</div>

			<div
				v-if="statshr.LstFedTagAvail"
				class="my-1"
			>
				<!-- IP divFedTag - INSERT -->
			</div>

			<v-text-field
				v-if="statshr.TxfFedCmtAvail"
				class="my-1"
				v-model="contiac.TxfFedCmt"
				:label="tag.CptFedCmt"
				:disabled="!statshr.TxfFedCmtActive"
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
		name: 'PnlWznmConDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmConDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmConDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmConDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmConDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmConDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmConDetail) this.contiac = dpcheng.ContIacWznmConDetail;
				if (dpcheng.ContInfWznmConDetail) this.continf = dpcheng.ContInfWznmConDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFLstFedTag) this.feedFLstFedTag = dpcheng.FeedFLstFedTag;
				if (dpcheng.FeedFLstFedVit) this.feedFLstFedVit = dpcheng.FeedFLstFedVit;
				if (dpcheng.FeedFLstOpt) this.feedFLstOpt = dpcheng.FeedFLstOpt;
				if (dpcheng.FeedFLstTag) this.feedFLstTag = dpcheng.FeedFLstTag;
				if (dpcheng.FeedFPupFedSrt) this.feedFPupFedSrt = dpcheng.FeedFPupFedSrt;
				if (dpcheng.FeedFPupHkt) this.feedFPupHkt = dpcheng.FeedFPupHkt;
				if (dpcheng.FeedFPupJti) this.feedFPupJti = dpcheng.FeedFPupJti;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupSco) this.feedFPupSco = dpcheng.FeedFPupSco;
				if (dpcheng.FeedFPupSty) this.feedFPupSty = dpcheng.FeedFPupSty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmConDetail) this.statapp = dpcheng.StatAppWznmConDetail;
				if (dpcheng.StatShrWznmConDetail) this.statshr = dpcheng.StatShrWznmConDetail;
				if (dpcheng.TagWznmConDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmConDetail);
					this.tag = dpcheng.TagWznmConDetail;
				}
				if (dpcheng.ContIacWznmConDetail) {
					for (let i = 0; i < this.feedFPupJti.length; i++)
						if (this.feedFPupJti[i].num == this.contiac.numFPupJti) {
							this.contapp.fiFPupJti = this.feedFPupJti[i];
							break;
						}
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
					for (let i = 0; i < this.feedFPupHkt.length; i++)
						if (this.feedFPupHkt[i].num == this.contiac.numFPupHkt) {
							this.contapp.fiFPupHkt = this.feedFPupHkt[i];
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
					for (let i = 0; i < this.feedFPupSty.length; i++)
						if (this.feedFPupSty[i].num == this.contiac.numFPupSty) {
							this.contapp.fiFPupSty = this.feedFPupSty[i];
							break;
						}
					for (let i = 0; i < this.feedFLstTag.length; i++)
						if (this.feedFLstTag[i].num == this.contiac.numFLstTag) {
							this.contapp.fiFLstTag = this.feedFLstTag[i];
							break;
						}
					for (let i = 0; i < this.feedFPupFedSrt.length; i++)
						if (this.feedFPupFedSrt[i].num == this.contiac.numFPupFedSrt) {
							this.contapp.fiFPupFedSrt = this.feedFPupFedSrt[i];
							break;
						}
					for (let i = 0; i < this.feedFLstFedVit.length; i++)
						if (this.feedFLstFedVit[i].num == this.contiac.numFLstFedVit) {
							this.contapp.fiFLstFedVit = this.feedFLstFedVit[i];
							break;
						}
					for (let i = 0; i < this.feedFLstFedTag.length; i++)
						if (this.feedFLstFedTag[i].num == this.contiac.numFLstFedTag) {
							this.contapp.fiFLstFedTag = this.feedFLstFedTag[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmConDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmConDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstClu: null,

			feedFLstFedTag: null,

			feedFLstFedVit: null,

			feedFLstOpt: null,

			feedFLstTag: null,

			feedFPupFedSrt: null,

			feedFPupHkt: null,

			feedFPupJti: null,

			feedFPupRet: null,

			feedFPupSco: null,

			feedFPupSty: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJti: null,

				fiFPupTyp: null,

				fiFLstClu: null,

				fiFPupHkt: null,

				fiFPupRet: null,

				fiFPupSco: null,

				fiFPupSty: null,

				fiFLstTag: null,

				fisFLstOpt: [],

				fiFPupFedSrt: null,

				fiFLstFedVit: null,

				fiFLstFedTag: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
