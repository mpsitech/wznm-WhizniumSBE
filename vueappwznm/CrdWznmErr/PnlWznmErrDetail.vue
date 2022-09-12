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

		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmErrDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmErrDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmErrDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmErrDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmErrDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmErrDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmErrDetail) this.contiac = dpcheng.ContIacWznmErrDetail;
				if (dpcheng.ContInfWznmErrDetail) this.continf = dpcheng.ContInfWznmErrDetail;
				if (dpcheng.FeedFPupJti) this.feedFPupJti = dpcheng.FeedFPupJti;
				if (dpcheng.StatAppWznmErrDetail) this.statapp = dpcheng.StatAppWznmErrDetail;
				if (dpcheng.StatShrWznmErrDetail) this.statshr = dpcheng.StatShrWznmErrDetail;
				if (dpcheng.TagWznmErrDetail) {
					Wznm.unescapeBlock(dpcheng.TagWznmErrDetail);
					this.tag = dpcheng.TagWznmErrDetail;
				}
				if (dpcheng.ContIacWznmErrDetail) {
					for (let i = 0; i < this.feedFPupJti.length; i++)
						if (this.feedFPupJti[i].num == this.contiac.numFPupJti) {
							this.contapp.fiFPupJti = this.feedFPupJti[i];
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
				if (srefIxWznmVDpch == "DpchEngWznmErrDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmErrDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupJti: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJti: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
