<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstClu"
				return-object
				:items="feedFLstClu"
				item-value="num"
				item-text="tit1"
				:label="tag.CptClu"
				v-on:change="handleFiChange('numFLstClu', contapp.fiFLstClu)"
				:disabled="!statshr.LstCluActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupCnt"
				return-object
				:items="feedFPupCnt"
				item-value="num"
				item-text="tit1"
				:label="tag.CptCnt"
				v-on:change="handleFiChange('numFPupCnt', contapp.fiFPupCnt)"
				:disabled="!statshr.PupCntActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAcv"
				:label="tag.CptAcv"
				:disabled="!statshr.TxfAcvActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAnm"
				:label="tag.CptAnm"
				:disabled="!statshr.TxfAnmActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupMim"
				return-object
				:items="feedFPupMim"
				item-value="num"
				item-text="tit1"
				:label="tag.CptMim"
				v-on:change="handleFiChange('numFPupMim', contapp.fiFPupMim)"
				:disabled="!statshr.PupMimActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSiz"
				:label="tag.CptSiz"
				:disabled="!statshr.TxfSizActive"
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
		name: 'PnlWznmFilDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmFilDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmFilDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmFilDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmFilDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmFilDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmFilDetail) this.contiac = dpcheng.ContIacWznmFilDetail;
				if (dpcheng.ContInfWznmFilDetail) this.continf = dpcheng.ContInfWznmFilDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFPupCnt) this.feedFPupCnt = dpcheng.FeedFPupCnt;
				if (dpcheng.FeedFPupMim) this.feedFPupMim = dpcheng.FeedFPupMim;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.StatAppWznmFilDetail) this.statapp = dpcheng.StatAppWznmFilDetail;
				if (dpcheng.StatShrWznmFilDetail) this.statshr = dpcheng.StatShrWznmFilDetail;
				if (dpcheng.TagWznmFilDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmFilDetail);
					this.tag = dpcheng.TagWznmFilDetail;
				}
				if (dpcheng.ContIacWznmFilDetail) {
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupCnt.length; i++)
						if (this.feedFPupCnt[i].num == this.contiac.numFPupCnt) {
							this.contapp.fiFPupCnt = this.feedFPupCnt[i];
							break;
						}
					for (let i = 0; i < this.feedFPupMim.length; i++)
						if (this.feedFPupMim[i].num == this.contiac.numFPupMim) {
							this.contapp.fiFPupMim = this.feedFPupMim[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmFilDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmFilDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupCnt: null,

			feedFPupMim: null,

			feedFPupRet: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstClu: null,

				fiFPupRet: null,

				fiFPupCnt: null,

				fiFPupMim: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
