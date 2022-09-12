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
				v-model="continf.TxtCpb"
				:label="tag.CptCpb"
			/>

			<div
				class="my-1"
			>
				<!-- IP divGrp - INSERT -->
			</div>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmTagDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmTagDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTagDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmTagDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmTagDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmTagDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmTagDetail) this.contiac = dpcheng.ContIacWznmTagDetail;
				if (dpcheng.ContInfWznmTagDetail) this.continf = dpcheng.ContInfWznmTagDetail;
				if (dpcheng.FeedFPupGrp) this.feedFPupGrp = dpcheng.FeedFPupGrp;
				if (dpcheng.FeedFPupJti) this.feedFPupJti = dpcheng.FeedFPupJti;
				if (dpcheng.StatAppWznmTagDetail) this.statapp = dpcheng.StatAppWznmTagDetail;
				if (dpcheng.StatShrWznmTagDetail) this.statshr = dpcheng.StatShrWznmTagDetail;
				if (dpcheng.TagWznmTagDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmTagDetail);
					this.tag = dpcheng.TagWznmTagDetail;
				}
				if (dpcheng.ContIacWznmTagDetail) {
					for (let i = 0; i < this.feedFPupJti.length; i++)
						if (this.feedFPupJti[i].num == this.contiac.numFPupJti) {
							this.contapp.fiFPupJti = this.feedFPupJti[i];
							break;
						}
					for (let i = 0; i < this.feedFPupGrp.length; i++)
						if (this.feedFPupGrp[i].num == this.contiac.numFPupGrp) {
							this.contapp.fiFPupGrp = this.feedFPupGrp[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmTagDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmTagDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupGrp: null,

			feedFPupJti: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJti: null,

				fiFPupGrp: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
