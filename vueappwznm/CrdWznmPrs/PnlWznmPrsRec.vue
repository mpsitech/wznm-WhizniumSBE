<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWznmVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWznmPrsDetail
						v-on:request="handleRequest"
						ref="PnlWznmPrsDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmPrsADetail
						v-on:request="handleRequest"
						ref="PnlWznmPrsADetail"
						:scrJref=statshr.scrJrefADetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmPrsMNProject
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPrsMNProject"
						:scrJref=statshr.scrJrefMNProject
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmPrsDetail from './PnlWznmPrsDetail';
	import PnlWznmPrsADetail from './PnlWznmPrsADetail';
	import PnlWznmPrsMNProject from './PnlWznmPrsMNProject';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmPrsRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmPrsDetail,
			PnlWznmPrsADetail,
			PnlWznmPrsMNProject
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmPrsRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmPrsRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmPrsRec) this.continf = dpcheng.ContInfWznmPrsRec;
				if (dpcheng.StatAppWznmPrsRec) this.statapp = dpcheng.StatAppWznmPrsRec;
				if (dpcheng.StatShrWznmPrsRec) this.statshr = dpcheng.StatShrWznmPrsRec;
				if (dpcheng.TagWznmPrsRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmPrsRec);
					this.tag = dpcheng.TagWznmPrsRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPrsDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefADetail) this.$refs.PnlWznmPrsADetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNProject) this.$refs.PnlWznmPrsMNProject.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmPrsRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmPrsRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPrsDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefADetail) this.$refs.PnlWznmPrsADetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNProject) this.$refs.PnlWznmPrsMNProject.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
