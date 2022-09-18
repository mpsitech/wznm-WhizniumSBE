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
				return-object
				:items="feedFPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTyp"
				v-on:change="handleFiChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtVer"
				:label="tag.CptVer"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

			<v-text-field
				v-if="statshr.TxtCarAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCar"
				:label="tag.CptCar"
			/>

			<v-select
				v-if="statshr.LstUnqAvail"
				class="my-1"
				v-model="contapp.fiFLstUnq"
				return-object
				:items="feedFLstUnq"
				item-value="num"
				item-text="tit1"
				:label="tag.CptUnq"
				v-on:change="handleFiChange('numFLstUnq', contapp.fiFLstUnq)"
				:disabled="!statshr.LstUnqActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

			<v-divider v-if="statshr.SepPstAvail"/>

			<h3
				v-if="statshr.HdgPstAvail"
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

			<v-select
				v-if="statshr.PupPstJtiAvail"
				class="my-1"
				v-model="contapp.fiFPupPstJti"
				return-object
				:items="feedFPupPstJti"
				item-value="num"
				item-text="tit1"
				:label="tag.CptPstJti"
				v-on:change="handleFiChange('numFPupPstJti', contapp.fiFPupPstJti)"
				:disabled="!statshr.PupPstJtiActive"
			/>

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
				return-object
				:items="feedFPupPstSco"
				item-value="num"
				item-text="tit1"
				:label="tag.CptPstSco"
				v-on:change="handleFiChange('numFPupPstSco', contapp.fiFPupPstSco)"
				:disabled="!statshr.PupPstScoActive"
			/>

			<v-select
				v-if="statshr.PupPstAtyAvail"
				class="my-1"
				v-model="contapp.fiFPupPstAty"
				return-object
				:items="feedFPupPstAty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptPstAty"
				v-on:change="handleFiChange('numFPupPstAty', contapp.fiFPupPstAty)"
				:disabled="!statshr.PupPstAtyActive"
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
		name: 'PnlWznmTblDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmTblDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTblDetailDo": {
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

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmTblDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmTblDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmTblDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmTblDetail) this.contiac = dpcheng.ContIacWznmTblDetail;
				if (dpcheng.ContInfWznmTblDetail) this.continf = dpcheng.ContInfWznmTblDetail;
				if (dpcheng.FeedFLstUnq) this.feedFLstUnq = dpcheng.FeedFLstUnq;
				if (dpcheng.FeedFPupPstAty) this.feedFPupPstAty = dpcheng.FeedFPupPstAty;
				if (dpcheng.FeedFPupPstJti) this.feedFPupPstJti = dpcheng.FeedFPupPstJti;
				if (dpcheng.FeedFPupPstSco) this.feedFPupPstSco = dpcheng.FeedFPupPstSco;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWznmTblDetail) this.statapp = dpcheng.StatAppWznmTblDetail;
				if (dpcheng.StatShrWznmTblDetail) this.statshr = dpcheng.StatShrWznmTblDetail;
				if (dpcheng.TagWznmTblDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmTblDetail);
					this.tag = dpcheng.TagWznmTblDetail;
				}
				if (dpcheng.ContIacWznmTblDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFLstUnq.length; i++)
						if (this.feedFLstUnq[i].num == this.contiac.numFLstUnq) {
							this.contapp.fiFLstUnq = this.feedFLstUnq[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmTblDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmTblDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstUnq: null,

			feedFPupPstAty: null,

			feedFPupPstJti: null,

			feedFPupPstSco: null,

			feedFPupRet: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupRet: null,

				fiFLstUnq: null,

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
