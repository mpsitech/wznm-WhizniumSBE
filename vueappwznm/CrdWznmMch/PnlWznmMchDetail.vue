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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCch"
				:label="tag.CptCch"
			/>

			<div
				class="my-1"
			>
				<!-- IP divPkm - INSERT -->
			</div>

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
		name: 'PnlWznmMchDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmMchDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmMchDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmMchDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmMchDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmMchDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmMchDetail) this.contiac = dpcheng.ContIacWznmMchDetail;
				if (dpcheng.ContInfWznmMchDetail) this.continf = dpcheng.ContInfWznmMchDetail;
				if (dpcheng.FeedFPupPkm) this.feedFPupPkm = dpcheng.FeedFPupPkm;
				if (dpcheng.StatAppWznmMchDetail) this.statapp = dpcheng.StatAppWznmMchDetail;
				if (dpcheng.StatShrWznmMchDetail) this.statshr = dpcheng.StatShrWznmMchDetail;
				if (dpcheng.TagWznmMchDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmMchDetail);
					this.tag = dpcheng.TagWznmMchDetail;
				}
				if (dpcheng.ContIacWznmMchDetail) {
					for (let i = 0; i < this.feedFPupPkm.length; i++)
						if (this.feedFPupPkm[i].num == this.contiac.numFPupPkm) {
							this.contapp.fiFPupPkm = this.feedFPupPkm[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmMchDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmMchDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupPkm: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupPkm: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
