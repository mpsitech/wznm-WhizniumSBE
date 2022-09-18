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

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJti"
				return-object
				:items="feedFPupJti"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJti"
				v-on:change="handleFiChange('numFPupJti', contapp.fiFPupJti)"
				:disabled="!statshr.PupJtiActive"
			/>

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
				return-object
				:items="feedFPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTyp"
				v-on:change="handleFiChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			/>

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
				v-model="continf.TxtHku"
				:label="tag.CptHku"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

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
				return-object
				:items="feedFPupSco"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSco"
				v-on:change="handleFiChange('numFPupSco', contapp.fiFPupSco)"
				:disabled="!statshr.PupScoActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSty"
				return-object
				:items="feedFPupSty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSty"
				v-on:change="handleFiChange('numFPupSty', contapp.fiFPupSty)"
				:disabled="!statshr.PupStyActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstTag"
				return-object
				:items="feedFLstTag"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTag"
				v-on:change="handleFiChange('numFLstTag', contapp.fiFLstTag)"
				:disabled="!statshr.LstTagActive"
			/>

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

			<v-select
				class="my-1"
				v-model="contapp.fisFLstOpt"
				multiple
				return-object
				:items="feedFLstOpt"
				item-value="num"
				item-text="tit1"
				:label="tag.CptOpt"
				v-on:change="handleFisChange('numsFLstOpt', contapp.fisFLstOpt)"
				:disabled="!statshr.LstOptActive"
			/>

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

			<v-text-field
				v-if="statshr.TxtFedSruAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFedSru"
				:label="tag.CptFedSru"
			/>

			<v-select
				v-if="statshr.LstFedVitAvail"
				class="my-1"
				v-model="contapp.fiFLstFedVit"
				return-object
				:items="feedFLstFedVit"
				item-value="num"
				item-text="tit1"
				:label="tag.CptFedVit"
				v-on:change="handleFiChange('numFLstFedVit', contapp.fiFLstFedVit)"
				:disabled="!statshr.LstFedVitActive"
			/>

			<v-select
				v-if="statshr.LstFedTagAvail"
				class="my-1"
				v-model="contapp.fiFLstFedTag"
				return-object
				:items="feedFLstFedTag"
				item-value="num"
				item-text="tit1"
				:label="tag.CptFedTag"
				v-on:change="handleFiChange('numFLstFedTag', contapp.fiFLstFedTag)"
				:disabled="!statshr.LstFedTagActive"
			/>

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
	import vecio from '../../scripts/vecio';

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

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			handleFisChange: function(cisref, fis) {
				var nums = new Uint32Array(fis.length);

				for (let i = 0; i < fis.length; i++) nums[i] = fis[i].num;
				this.contiac[cisref] = vecio.toBase64(nums);

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
					var fisFLstOpt = [];
					var numsFLstOpt = vecio.parseUintvec(this.contiac.numsFLstOpt);

					for (let i = 0; i < this.feedFLstOpt.length; i++)
						if (numsFLstOpt.includes(this.feedFLstOpt[i].num))
							fisFLstOpt.push(this.feedFLstOpt[i]);

					this.contapp.fisFLstOpt = fisFLstOpt;
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
